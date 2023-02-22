# The Game of Missiles
---

## TODO
- [ ] Add Images and commands here on how to play. 
- [ ] Add an option for enabling AI (currently AI is defaultly enabled)


## How to play


## Questions for the assignment

### Write an overview of how your AI works, including how it detects where projectiles will fall and how it chooses where to go.

My algorithm works by first checking if there are any projectiles in the air and how many of them have less than 5 secs to fall. If there are, it will check if the projectile is going to hit the player. If it is, it will move the player to the left or right depending on which side of the player the projectile is on. 

In my `determineSafeSpots` function I iterate over all the existing projectiles and predict where they will fall, and the time to fall using `trackProjectile` functions. I then check if the projectile is going to hit the player. If it is I use the `explodingPosition` function to determine where the projectile will explode. 

I then check if the player is going to be hit by the explosion as shown in the `pickSafeSpot` function. If it is, I determine which side of the player the projectile is on and move the player to the left or right by checking which side is shorter.

I only take one step either left or right per frame, so even if multiple projectiles are going to hit the player, I limit my player to only moving once.

#### What challenges did you face when writing an AI?

I had to figure out how to predict where the projectiles will fall and how to determine if the player is going to be hit by the explosion. I also had to figure out how to move the player to the left or right depending on which side of the player the projectile is on. These were minor challenges, which were solved.

#### How well does your AI work in a Hard scenario? If it doesn’t work, why? If it does, try harder scenarios and see when it does fail and explain why?

My AI works well in the Medium scenario. It can avoid all the projectiles and move the player to the left or right depending on which side of the player the projectile is on. But for the hard scenario, it fails to avoid all the projectiles. This is because the algorithm only takes one step either left or right per frame, so even if multiple projectiles are going to hit the player, I limit my player to only moving once.

Also, there are situations where there are no safe spots for the player to move, which could result in the player being hit regardless of the algorithm's decision-making. 

#### What did you think of the assignment and did it meet its goals? Why or why not?

I thought the assignment was fun and challenging. It was a good way to get familiar with the programming environment and the C++ codebase. It also helped me understand how to use the game engine work and how to write an AI for a game. I think it met its goals because it was meant to be a familiarization task and it checked all the boxes.

## Poem
```text
In this game of missiles, we dance with fate
As projectiles rain down from a fiery gate
Each frame counts, each move a gamble
As we try to avoid the missile's deadly ramble

We dodge and weave with limited speed
As missiles chase us with a vengeful greed
Our hearts race with each calculated step
As we try to cheat death with every move

The sky above is a fiery maelstrom
As the missiles explode with a deafening bang
We fight to survive with all our might
As the battlefield turns into a never-ending fight

Yet amidst the chaos and the endless rain
We find a moment to pause and regain
Our spirits lift with each narrow escape
As we triumph over each missile's deadly fate
```


