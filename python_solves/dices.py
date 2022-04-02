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
    sides = [int(x) for x in case_input[1].split()]

    sides.sort()

    tot = 0
    i = 1
    for _, side in enumerate(sides):
        if i <= side:
            tot += 1
            i += 1
        else: # discard that dice and continue
            pass

    solution = tot
    print_output(
        f"Case #{case}: " + str(solution), OUTPUT_LINES,
    )


def run(INPUT_LINES: List[str] = None, OUTPUT_LINES: List[str] = None):
    N_CASE = int(read_input(INPUT_LINES))
    ALL_CASES_INPUT: List[List[str]] = []

    for case in range(N_CASE):
        CASE_INPUT = [
            read_input(INPUT_LINES),
            read_input(INPUT_LINES),
        ]
        ALL_CASES_INPUT.append(CASE_INPUT)

    for i, case_input in enumerate(ALL_CASES_INPUT):
        solve(i + 1, case_input, OUTPUT_LINES)


if __name__ == "__main__":
    run()
