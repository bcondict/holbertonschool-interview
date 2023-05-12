#!/usr/bin/python3
"""
Query Reddit API, parse titles of all hot articles, and print a sorted count of
given keywords (case-insensitive, delimited by spaces
"""

import requests


def count_words(subreddit, word_list, counts={}, after=''):
    """
        method that queries the Reddit API, parses the title of all hot
        articles and prints a sorted count of given keywords
        (case-insensitive, delimited by spaces.
    """

    if len(counts) <= 0:
        for word in word_list:
            counts[word.lower()] = 0

    if after is None:
        sorted_counts = dict(sorted(
            counts.items(),
            key=lambda x: (x[1], x[0]),
            reverse=True
            ))
        for word, count in sorted_counts.items():
            if count > 0:
                print("{}: {}".format(word, count))
        return None

    url = "https://api.reddit.com/r/{}/hot.json".format(subreddit)
    params = {'limit': 100, 'after': after}
    headers = {'user-agent': 'holberton_school'}
    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return None

    after = response.json().get("data").get("after")
    children = response.json().get("data").get("children")
    for child in children:
        title = child.get("data").get("title").lower().split(" ")
        for word in word_list:
            counts[word.lower()] += title.count(
                word.lower())
    count_words(subreddit, word_list, counts, after)
