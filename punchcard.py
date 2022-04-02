def solve(case_input: list[str], OUTPUT_LINES: list[str] = None):
    R_C = case_input[0]
    R, C = [int(x) for x in R_C.split()]
    lines = []

    sep_line = '+' + '+'.join('-' * C) + '+'
    content = '|' + '|'.join('.' * C) + '|'

    lines = [content] * R
    lines[0] = '.' + lines[0][1:]

    res = ('\n' + sep_line + '\n').join(lines)

    res = sep_line + '\n' + res + '\n' + sep_line
    res = '..' + res[2:]

    lines = res.splitlines()

    for li in lines:
        print(li)
        if OUTPUT_LINES:
            correct = OUTPUT_LINES.pop(0)
            assert li == correct, f"\n{li}\nshould be:\n{correct}"


if __name__ == "__main__":
    LINES_INPOUT = """
3
3 4
2 2
2 3
""".splitlines()[
        1:
    ]
    N_CASE = int(LINES_INPOUT.pop(0))
    OUTPUT_LINES = """
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
""".splitlines()[
        1:
    ]

else:
    N_CASE = int(input())
    LINES_INPOUT = []
    OUTPUT_LINES = None
    for case in range(N_CASE):
        LINES_INPOUT.append([input()])

for i, case_input in enumerate(LINES_INPOUT):
    li = f"Case #{i+1}:"
    if OUTPUT_LINES:
        correct = OUTPUT_LINES.pop(0)
        assert li == correct, f"\n{li}\nshould be:\n{correct}"

    print(li)
    solve(case_input, OUTPUT_LINES)
