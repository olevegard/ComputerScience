#!/bin/sh

git filter-branch --env-filter '
if [ $GIT_COMMIT = 01a0fa0a8242a25d19 ]
then
    export GIT_AUTHOR_DATE="Fri Jun 6 12:38:53 2014 -0800"
    export GIT_COMMITTER_DATE="Fri Jun 12 01:01:01 2014 -0700"
fi
'
