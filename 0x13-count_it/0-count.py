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
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

    headers = {'User-agent': 'holberton_school'}
    params = {'limit': 100, 'after': after}

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get('data').get('children')
    after = response.json().get('data').get('after')

    for child in data:
        title = child.get('data').get('title').lower()

        for word in word_list:
            ocurrences = title.count(word.lower())
            if ocurrences > 0:
                if word.lower() not in counts:
                    counts[word.lower()] = ocurrences
                else:
                    counts[word.lower()] += ocurrences

    if after:
        return count_words(subreddit, word_list, counts, after)

    else:
        if not counts:
            return

        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            print("{}: {}".format(word, count))

    return
