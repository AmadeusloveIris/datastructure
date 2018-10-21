#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: amadeus
# Created Time : 2018年10月20日 星期六 10时56分21秒
# File Name: baoli.py
# Description:
"""
class Solution:
      # @param {string} s
      # @return {boolean}
      @classmethod
      def isValid(cls,s):
          m = {'(':')','[':']','{':'}'}
          stacklist = []
          for p in s:
              if p in('(','{','['):
                  stacklist.append(p)
              else:
                  if not stacklist or p != m[stacklist[-1]]:
                      return False
                  else:
                      stacklist.pop()
          if not stacklist:return True
          else:return False

if __name__ == "__main__":
    rownum = int(input())
    for a in range(rownum):
        for i in input().splitlines():
            if (Solution.isValid(i)):
                print("Yes\n")
            else:
                print("No\n")
    pass
