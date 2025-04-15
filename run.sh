#!/bin/bash

# Step 1: Push current commit
git push

# Step 2: Run main.py to update README and charts
python3 update_readme.py

# Step 3: Amend last commit to include README.md + charts, without changing message
git add README.md chart.png daily_chart.png
git commit --amend --no-edit

# Step 4: Force push the amended commit
git push --force
