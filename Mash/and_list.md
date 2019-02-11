
# And List

Ever wanted to do something like:

```Bash
git pull
git push
```

In one line? Or:

```Bash
vagrant up
vagrant ssh
```

Or:

```Bash
gcc -g -c blah.c
gcc -g -o blah.o
```

Well in Bash you can do the following two different things:

```Bash
git pull && git push    # works in one line but had to rewrite git
git {pull, push}        # translates to 'git pull push' which is wrong
```

In mash there's a syntax to combine those:

```Mash
git &{pull,push}        # translates to 'git pull && git push`
```

You can have as long of a comma delimited list of command additions as you want:

```Mash
git &{add -p, commit -m "did work", push -f}
```

Is the same thing as:

```Mash
git add -p
git commit -m "did work"
git push -f
```


