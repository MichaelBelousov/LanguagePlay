
# Mash

## Mike's Apathetic SHell

Not actually a full design for a shell. Just a collection of 
hypothetically useful shell language fragments.

check out the [And List](Mash/add_list.md) and other files in the 
directory for examples of language features for this hypothetical 
shell.


the And List functionality looks something like:

```Mash
git &{add scripts/newscript,commit -m "added new script", push -f}
# in bash you would do:
git add scripts/newscript && git commit -m "added new script" && git push -f
```
