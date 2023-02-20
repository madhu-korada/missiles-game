#include "Controller.h"
#include <cmath>
#include <iostream>
namespace mrsd
{
	void Controller::control(const mrsd::Game& g, float t)
	{
		currentTime += t;
		if (logger) std::cout << "\nCurrent time t is  " << currentTime << std::endl;

		std::vector<int> dangerZone(g.getWidth()+1, 0);
		determineSafeSpots(g, dangerZone); // determine safe spots
		int move = pickSafeSpot(g, dangerZone); // pick safe spot 
		if(p != 0 && move != 0) // move player
		{
			if (logger) std::cout << "Player is at " << p->x << " and is moving to " << move << std::endl;
			p->x += move;
		}
	}

	void Controller::createPlayer(Game& g)
	{
		if(p == 0)
		{
			p = new Player();
			p->dead = true;
		}
		if(p->dead)
		{
			p->dead = false;
			p->x = g.getWidth()/2;
			g.newPlayer(p);
		}
	}

	Prediction Controller::trackProjectile(const Projectile& p, const Game& g)
	{
		Prediction pred;
		pred.t = (-p.vy - sqrt(p.vy*p.vy - 2 * g.getGravity() * p.y)) / g.getGravity();
		pred.x = p.x + p.vx * pred.t;
		if (logger) std::cout << "projectile info, p.x: " << p.x << " p.y: " << p.y << " p.vx: " << p.vx << " p.vy: " << p.vy << " pred t: " << pred.t << " pred x: " << pred.x << std::endl;
		return pred;
	}

	void Controller::determineSafeSpots(const Game& g, std::vector<int>& dangerZone)
	{
		auto projectiles = g.getProjectiles();
		for(std::list<Projectile>::iterator it = projectiles.begin(); it != projectiles.end();++it)
		{
			Prediction pred = trackProjectile(*it, g);
			if(pred.t < 5.0){
				explodingPosition(g, pred.x, dangerZone);
			}
		}
		if (logger){
			std::cout << "Danger Zone: ";
			for (int j = 0; j < dangerZone.size(); ++j)
			{
				if (p && j == p->x){
					std::cout << "--";
				}
				std::cout << dangerZone[j];
			}
			std::cout << std::endl;
		}
	}

	void Controller::explodingPosition(const Game& g, const float& x, std::vector<int>& dangerZone)
	{
		for(int i = std::floor(x - g.explosionSize);
				i <= std::ceil(x + g.explosionSize);
				++i)
		{
			if( i >= 0 && i <= g.getWidth() )
				dangerZone[i]++;
		}
	}

	int Controller::pickSafeSpot(const Game& g, std::vector<int>& dangerZone)
	{
		bool safe = true;
		if (p != 0)
		{
			for (int i = p->x - 5; i <= p->x + 5; ++i)
			{
				if (dangerZone[i] != 0)
				{
					safe = false;
					break;
				}
			}
		}

		if(p && !safe){
			if (logger) std::cout << "my curr pos is: " << p->x << std::endl;
			// check the left side
			int left = p->x, right = p->x, currPos = p->x;
			int leftDist = 0, rightDist = 0;
			for(int i = currPos - 1; i >= 5; --i)
			{
				if(dangerZone[i] == 0 && dangerZone[i-1] == 0 && dangerZone[i-2] == 0)
				{
					left = i-2;
					break;
				}
			}
			// check the right side
			for(int i = currPos + 1; i < g.getWidth() - 5; ++i)
			{
				if(dangerZone[i] == 0 && dangerZone[i+1] == 0 && dangerZone[i+2] == 0)
				{
					right = i+2;
					break;
				}
			}
			leftDist = currPos - left;
			rightDist = right - currPos;
			if (logger) std::cout << "left: " << left << " right: " << right << " leftDist: " << leftDist << " rightDist: " << rightDist << std::endl;
			
			return leftDist < rightDist ? -1 : leftDist > rightDist ? 1 : 0;
		}
		return 0;
	}
}
