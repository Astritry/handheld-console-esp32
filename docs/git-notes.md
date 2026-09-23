Git Bash cheat sheet
Navigation
pwd                 # show current folder path
ls                  # list files here
ls -a               # list files, including hidden ones (.git, .gitignore)
cd foldername       # move into a folder
cd ..               # move up one level
cd /c/Users/Belisar/Documents/handheld-console-esp32   # jump to exact path (C:\ becomes /c/, \ becomes /)
Easiest way to move into a folder: type cd (with the space), then drag the folder from File Explorer into the Git Bash window, it fills in the correct path for you.

Checking repo status
git status          # see what changed, and whether you're up to date with GitHub

Creating files/folders
mkdir docs                          # create a folder
touch docs/research.md              # create an empty file inside it

The 3-command save cycle (your main daily loop)
git add .
git commit -m "short description of what you changed"
git push
git add . stages every change you made
git commit -m "..." saves a snapshot with a message
git push uploads it to GitHub

Opening the project in an editor
code .              # opens the whole folder in VS Code

Resuming work after shutting down

1. Open Git Bash in the right folder
Easiest way: open File Explorer, navigate into your handheld-console-esp32 folder, right-click empty space inside it, choose "Git Bash Here". This skips all the cd/path typing entirely.

If you only have a plain Git Bash window open instead:
cd ~/handheld-console-esp32
(~ means your home folder, so this works as long as the repo is directly inside it, which yours is.)

2. Check nothing's missing or out of sync
git status
Should say working tree clean and up to date with origin/main, since you pushed everything before shutting down.

3. Pull, in case you changed something from another device or browser

git pull
This downloads any changes from GitHub that aren't on this PC yet. Skip it if you only ever edit from this one computer, but it's a safe habit regardless, and important once you're not the only one touching the repo.

4. Open your editor

code .

Opens the whole project in VS Code, ready to edit.

5. Work, then before shutting down again
git add .
git commit -m "what you did this session"
git push
