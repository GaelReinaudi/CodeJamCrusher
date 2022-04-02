from typing import List
import punchcard

if __name__ == "__main__":
    INPUT_LINES = \
"""

3
3 4
2 2
2 3

""".splitlines()
    INPUT_LINES = [line for line in INPUT_LINES if line]
    OUTPUT_LINES = \
"""

Case #1:
..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
Case #2:
..+-+
..|.|
+-+-+
|.|.|
+-+-+
Case #3:
..+-+-+
..|.|.|
+-+-+-+
|.|.|.|
+-+-+-+

""".splitlines()
    OUTPUT_LINES = [line for line in OUTPUT_LINES if line]


punchcard.run(INPUT_LINES=INPUT_LINES, OUTPUT_LINES=OUTPUT_LINES)

