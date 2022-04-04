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


class Node:
    def __init__(self, n, fun, fun_points) -> None:
        self.n: int = n
        self.fun: int = fun
        self.kids: List[Node] = []
        for num, fun, point in fun_points:
            if point == self.n:
                self.kids.append(Node(n=num, fun=fun, fun_points=fun_points))

    def total_fun(self):
        if not self.kids:
            return (
                self.fun,
                0,
            )

        kids_fun = [k.total_fun() for k in self.kids]

        kids_fun.sort(key=lambda ft: ft[0])

        # the kid with smallest max_fun along the hierarchy
        smallest_kid = kids_fun.pop(0)

        max_fun = max([smallest_kid[0], self.fun])
        max_tot = smallest_kid[1]

        rest_fun = sum([k[1] for k in kids_fun]) + sum([k[0] for k in kids_fun])

        return max_fun, rest_fun + max_tot


def get_input(INPUT_LINES: List[str] = None,):
    N_CASE = int(read_input(INPUT_LINES))
    ALL_CASES_INPUT: List[List[str]] = []

    for case in range(N_CASE):
        CASE_INPUT = [
            read_input(INPUT_LINES),
            read_input(INPUT_LINES),
            read_input(INPUT_LINES),
        ]
        ALL_CASES_INPUT.append(CASE_INPUT)
    return ALL_CASES_INPUT


def solve(case: int, case_input: List[str], OUTPUT_LINES: List[str] = None):
    num_nodes = int(case_input[0])
    funs = [int(x) for x in case_input[1].split()]
    points = [int(x) for x in case_input[2].split()]
    fun_points = list(zip(range(1, num_nodes + 1), funs, points))

    abyss = Node(n=0, fun=0, fun_points=fun_points)

    fun, total_fun = abyss.total_fun()
    solution = total_fun + fun
    return solution


def run(INPUT_LINES: List[str] = None, OUTPUT_LINES: List[str] = None):
    ALL_CASES_INPUT = get_input(INPUT_LINES=INPUT_LINES)

    for i, case_input in enumerate(ALL_CASES_INPUT):
        solve(i + 1, case_input, OUTPUT_LINES)


def run_parallel(INPUT_LINES: List[str] = None, OUTPUT_LINES: List[str] = None):
    import multiprocessing

    ALL_CASES_INPUT = get_input(INPUT_LINES=INPUT_LINES)

    pool = multiprocessing.Pool(8)
    solutions = [
        pool.apply(solve, args=(i + 1, case_input))
        for i, case_input in enumerate(ALL_CASES_INPUT)
    ]
    pool.close()

    for case, s in enumerate(solutions):
        print_output(f"Case #{case}: " + str(s),)


if __name__ == "__main__":
    run()
