#!/bin/bash
git add .
for file in $(git diff --cached --name-only); do
  if [[ ! "$file" =~ \. ]]; then
    git reset "$file"
  fi
done
git commit -m "${1:-"Update"}"
git push
