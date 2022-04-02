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


def solve(case: int, case_input: List[str], OUTPUT_LINES: List[str] = None):
    CMYKs = [[int(x) for x in cmyk.split()] for cmyk in case_input]

    common = [min([CMYKs[p][i] for p in range(3)]) for i in range(4)]

    TOTAL_NEEDED = 1000000
    tot = 0
    solution = [0] * 4
    for i in range(4):
        need = TOTAL_NEEDED - tot
        use = min(common[i], need)
        solution[i] += use
        tot += use

    if tot < TOTAL_NEEDED:
        print_output(f"Case #{case}: IMPOSSIBLE", OUTPUT_LINES)
    else:
        print_output(
            f"Case #{case}: " + " ".join([str(s) for s in solution]), OUTPUT_LINES,
        )


def run(INPUT_LINES: List[str] = None, OUTPUT_LINES: List[str] = None):
    N_CASE = int(read_input(INPUT_LINES))
    ALL_CASES_INPUT: List[List[str]] = []

    for case in range(N_CASE):
        CASE_INPUT = [
            read_input(INPUT_LINES),
            read_input(INPUT_LINES),
            read_input(INPUT_LINES),
        ]
        ALL_CASES_INPUT.append(CASE_INPUT)

    for i, case_input in enumerate(ALL_CASES_INPUT):
        solve(i + 1, case_input, OUTPUT_LINES)


if __name__ == "__main__":
    run()
