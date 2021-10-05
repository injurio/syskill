#!/bin/bash

# https://ss64.com/bash/curl.html
# https://ss64.com/bash/grep.html

curl -s https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw | grep -m 10 -o "flag|[A-Za-z]*\s*[A-Za-z]*" | cut -d '|' -f 2