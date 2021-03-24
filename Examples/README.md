# Documentation
This file will tell you how to make single-track music with Windows Console Sound Player.

## Structure
It's very simple.Just like this:
```
[statement1]
[statement2]
...
[statementn]
```
Very simple. Right?
Every statement using the follow format:
```
[operator] [args...]
```
Now I'm going to tell you how to write the statements.

## Operations

### Operation `1`
The `1` will play a sound.
Such like this:
```
1 440 1000
```
It will play the note 'A' for one second.
Format:
```
1 [freq] [time:ms]
```

### Operation `3`
The `3` will define a **template**.
You can play the **template** using operation `4`.
Format:
```
3 [freq]
```
Counting start by 1.

### Operation `4`
It will play a sound like `1` but use the template which you defined instead of frequence.
Format:
```
4 [template_index] [time:ms]
```

### Operation `5`
It's just a comment.
Format:
```
5 [...]
```
### Operation `0`
It will pause the playing with its argument.
Format:
```
0 [time:ms]
```

## Example
Here is an example to make you understand operations `1`,`3`,`4`,`5` and `0`.
```
5 This is a comment
5 1 to play,0 to pause;3 to add template; 4 to play template;2 to 
5 play previous one.
1 658 200
1 658 200
3 658
0 200
4 1 200
0 200
1 540 200
1 658 200
0 200
1 784 200
0 600
1 392 600
```
You can see more examples in the directory.
One more thing, don't type enter in the end of the file.
