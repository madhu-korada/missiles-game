# This is a Game of Missiles
---
## How to play

### Write an overview of how your AI works, including how it detects where projectiles will fall and how it chooses where to go.

My algorithm works by first checking if there are any projectiles in the air and how many of them have less than 5 secs to fall. If there are, it will check if the projectile is going to hit the player. If it is, it will move the player to the left or right depending on which side of the player the projectile is on. 

In my `determineSafeSpots` function I iterate over all the existing projectiles and predict where they will fall, and the time to fall using `trackProjectile` functions. I then check if the projectile is going to hit the player. If it is I use `explodingPosition` function to determine where the projectile will explode. 

I then check if the player is going to be hit by the explosion as shown in `pickSafeSpot` function. If it is, I determine which side of the player the projectile is on and move the player to the left or right by checking which side is shorter.

I only take one step either left or right per frame, so even if there are multiple projectiles that are going to hit the player, I limit my player to only move once.

#### What challenges did you face when writing an AI?



#### How well does your AI work on a Hard scenario? If it doesn’t work, why? If it does, try harder scenarios and see when it does fail and explain why?

#### What did you think of the assignment and did it meet its goals? Why or why not?