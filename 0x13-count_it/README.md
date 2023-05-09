# 0x13. Count it!

Here is the task I solve to practive interview excercise. The solution the task is on the file with the same name than the task.

My challenge for you is to try to solve all of this task and after see the way I did it.

All the intellectual property belongs to Holberton School.

### General
#### Requirements
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- Libraries imported in your Python files must be organized in alphabetical order
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style
- All your files must be executable
- The length of your files will be tested using `wc`
- All your modules should have a documentation (`python3 -c 'print(__import__("my_module").__doc__)'`)
- You must use the Requests module for sending HTTP requests to the Reddit API

### Task
#### 0. Count it!
Write a recursive function that queries the [Reddit API](https://www.reddit.com/dev/api/), parses the title of all hot articles, and prints a sorted count of given keyword (case-insensitive, delimited by spaces. `Javascript` should count ad `javascript`, but `java` should not).

Requirements:
- Prorotype: `def count_words(subreddit, word_list)`
- Note: You may change the prototype, but it must be able to be called with just subreddit suplied and a list of keyword. AKA you can add a counter of anything else, but the function must worl without suppliying a starting value int tthe main.
- if `word_list` contains the same word (case-insensitive), the final count should be the sum of each duplicate (example below with `java`)
- Results should be printed in descending order, by the count, and if the count is the same for separate kwywords, they should then be sorted aphabetically (ascending, from A to Z). Words with no matches should be skipped and not printed. Words must be printed in lowecase.
- Results are based on the number of times a keyword appears, not titles it appears in. `java java java` counts as 3 separate occurrences of `java`.
- To make life easier, `java.` or `java!` or `java_` should not count as `java`
- If no posts match or the subreddit is invalid, print nothing.
- NOTE: invalid subreddits may retunr a redirect to search results. Esure that you are NOT following redirects.

Your code will NOT pass if you are using a loop and not recursively calling the function! This /can/ be thon with a loop but the point is to use a recursive function. :)

**Disclaimer**: number presented in this example cannot be accurate now - Reddit is hot articles are always changing.


### Usage
```bash
$ ./python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
$ python3 0-main.py programming 'JavA java'
java: 54
$ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
$ python3 0-main.py not_a_valid_subreddit 'python java'
```
