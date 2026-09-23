# Git Notes — ESP32 Handheld Console

Personal cheat sheet, built while learning Git for this project.

## Daily routine

**Starting a session:**
1. Open File Explorer → go into the `handheld-console-esp32` folder
                      → right-click empty space
                      → **"Git Bash Here"**.
   (or if Git Bash is already open elsewhere: `cd ~/handheld-console-esp32`)
2. `git status` — check everything is clean and up to date.
3. `git pull` — pull down any changes made from another device/browser. Safe to run even if nothing changed.
4. `code .` — open the folder in VS Code.

**Ending a session:**
```
git add .
git commit -m "what you did this session"
git push
```

## Navigation

```
pwd                 # show current folder path
ls                  # list files here
ls -a               # list files, including hidden ones (.git, .gitignore)
cd foldername       # move into a folder
cd ..               # move up one level
cd ~                # jump straight to home folder
```
Windows path → Git Bash path: `C:\Users\Belisar\Docs` becomes `/c/Users/Belisar/Docs`
(drive letter lowercase with a slash, backslashes become forward slashes)

Tip: Easiest way to move into any folder: type `cd ` (with the space), then drag the folder from File Explorer into the Git Bash window.

## Files and folders

```
mkdir docs                     # create a folder
touch docs/research.md         # create an empty file
rm filename                    # delete a file (careful, no undo)
rm -r foldername               # delete a folder and everything in it (careful)
mv oldname newname             # rename or move a file
```

## The core save cycle

```
git status                     # what changed since last commit?
git add .                      # stage everything changed
git add filename               # stage just one file
git commit -m "message"        # save a snapshot with a description
git push                       # upload commits to GitHub
git pull                       # download commits from GitHub
```

## Useful extras (not needed daily, but good to know)

```
git log                        # see commit history
git log --oneline              # same, but compact (one line per commit)
git diff                       # see exact line changes not yet staged
git diff --staged              # see exact line changes staged for commit
```

**Undoing mistakes:**
```
git restore filename           # discard uncommitted changes to a file (careful, no undo)
git reset HEAD~1                # undo the last commit, but keep the changes in your files
git commit --amend -m "new message"   # fix the message of your last commit (before pushing)
```

**Branches (for trying something risky without breaking working code):**
```
git branch                     # list branches
git branch feature-name        # create a new branch
git checkout feature-name      # switch to it
git checkout main              # switch back to main
git merge feature-name         # merge that branch's work into main (run this while on main)
```
Example use case: `git checkout -b test-buzzer-sound` before experimenting with new buzzer code, so `main` stays working no matter what happens.

**Ignoring files properly:**
```
cat .gitignore                 # see what's currently ignored
```
Add a line to `.gitignore` (e.g. `build/`) to stop Git from tracking that folder/file type.

**Cloning again on a different PC:**
```
git clone https://github.com/yourname/handheld-console-esp32.git
```

## Notes to self

- `.gitignore` and other dot-files are hidden by default — use `ls -a` to see them. Git still reads them fine either way.
- If a folder path with backslashes copied from File Explorer doesn't work in Git Bash, convert it, or just drag-and-drop the folder into the terminal instead.
- Commit small and often. A commit per "one thing done" (e.g. "Add button debounce", "Fix display rotation") is more useful later than one giant commit.

---

*This cheat sheet was put together with help from Claude (Anthropic) while I was learning Git for this project. Other documentation in this repo is written by me and checked with DeepL for language.*
