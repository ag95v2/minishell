#!/bin/sh

cat test_script.txt | valgrind --leak-check=full -v ./minishell
