# Taking Notes with Github

## The reason why I chose Github
This is my first time trying taking notes with Github.
I used to take notes with Notion, Confluence or some other Notes apps. 
But I found that it was quite hard for me to track back a particular line.
I would like to know the accurate time that I wrote this done and what I was thinking at that time.
Fortunately I came up with this idea. I'm able to achieve my goal with Git and Github commit log.
That is awesome.

## Future plan
I'm gonna migrate most of my notes here from other note apps.

## Tips
We have to use ssh to access github repository as we cannot check-in with https access now.
Previously Github allowed users to check-in with http access, but have to type user account and password every single time.
But for now http check-in is banned by Github.
Besides, ssh access is far more stable than http access as we have DNS contamination to Github here at China.

## Step to set up github enviroment on a new system
1. `git clone git@github.com:Sarcastiicc/Learning-Notes.git`
2. `git config --global user.email a1799255368@gmail.com`
3. `git config --global user.name Ning Dai`
4. Go to ~/.ssh and run `ssh-keygen -t rsa -b 4096 -C "a1799255368@gmail.com"
5. Copy the public key from *id_rsa.pub* to Github SSH key. It's gonna co-work with our local private key. 
   And we don't have to type the username and password whenever we're about to `git push`.
6. `git remote -v` to see the remote source
7. `ssh -T git@github.com`, once we got successful message, we've done.

