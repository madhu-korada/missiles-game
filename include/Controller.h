#pragma once
#include "Player.h"
#include "Game.h"
#include <map>
#include <vector>
namespace mrsd
{
	struct Prediction
	{
		float t, x;
	};
	class Controller
	{
		public:
			Controller():p(0), currentTime(0.0), logger(false){}
			/**
			 * Control AI based on state of game. "t" time has passed since last update.
			 **/
			void control(const Game& g, float t);
			/*
			 * Construct Player and add to game.
			 */
			void createPlayer(Game& g);
		private:
			Player* p;
			float currentTime;
			bool logger;
			Prediction pred;
			
			/*
			 * Track projectile and determine where and when it will hit ground.
			 */
			Prediction trackProjectile(const Projectile& p, const Game& g);

			/*
			 * Determine safe spots at time t based on state of all observed projectiles.
			 */
			void determineSafeSpots(const Game& g, std::vector<int>& dangerZone);

			/*
			 * Pick safe spot from determined safe spots.
			 */
			int pickSafeSpot(const Game& g, std::vector<int>& dangerZone);

			void explodingPosition(const Game& g, const float& x, std::vector<int>& dangerZone);
	};
}
