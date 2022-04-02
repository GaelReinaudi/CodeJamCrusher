
from typing import List


def print_output(line: str, OUTPUT_LINES: List[str] = None):
    assert type(line == str), f"not a string: {line}"
    print(line)
    if OUTPUT_LINES:
        correct = OUTPUT_LINES.pop(0)
        assert line == correct, f"\n{line}\nshould be:\n{correct}"


def read_input(INPUT_LINES: List[str] = None):
    if INPUT_LINES:
        return INPUT_LINES.pop(0)
    else:
        return input()


def solve(case_input: List[str], OUTPUT_LINES: List[str] = None):
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
        print_output(li, OUTPUT_LINES)


def run(INPUT_LINES: List[str] = None, OUTPUT_LINES: List[str] = None):
    N_CASE = int(read_input(INPUT_LINES))
    ALL_CASES_INPUT: List[List[str]] = []

    for case in range(N_CASE):
        CASE_INPUT = [read_input(INPUT_LINES)]
        ALL_CASES_INPUT.append(CASE_INPUT)

    for i, case_input in enumerate(ALL_CASES_INPUT):
        print_output(f"Case #{i+1}:", OUTPUT_LINES)
        solve(case_input, OUTPUT_LINES)


if __name__ == "__main__":
    run()
