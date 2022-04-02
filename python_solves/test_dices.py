import dices as solver

if __name__ == "__main__":
    INPUT_LINES = """

5
4
6 10 12 8
6
5 4 5 4 4 4
10
10 10 7 6 7 4 4 5 7 4
1
10
10
1 1 1 1 1 4 4 4 4 4



""".splitlines()
    INPUT_LINES = [line for line in INPUT_LINES if line]
    OUTPUT_LINES = """

Case #1: 4
Case #2: 5
Case #3: 9
Case #4: 1
Case #5: 4

""".splitlines()
    OUTPUT_LINES = [line for line in OUTPUT_LINES if line]


solver.run(INPUT_LINES=INPUT_LINES, OUTPUT_LINES=OUTPUT_LINES)

