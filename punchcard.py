def solve(case_input: str):
    R, C = [int(x) for x in case_input.split()]
    lines = []

    sep_line = '+' + '+'.join('-' * C) + '+'
    content = '|' + '|'.join('.' * C) + '|'

    lines = [content] * R
    lines[0] = '.' + lines[0][1:]
    res = ('\n' + sep_line + '\n').join(lines)

    res = sep_line + '\n' + res + '\n' + sep_line
    res = '..' + res[2:]
    return res


if __name__ == "__main__":
    LINES_INPOUT = \
"""
3
3 4
2 2
2 3
""".splitlines()[1:]
    N_CASE = int(LINES_INPOUT.pop(0))
    LINES_INPOUT

else:
    N_CASE = int(input())
    LINES_INPOUT = []
    for case in range(N_CASE):
        LINES_INPOUT.append([input()])

for i, case_input in enumerate(LINES_INPOUT):
    res = solve(case_input)
    print(f"Case #{i+1}:")
    print(res)
