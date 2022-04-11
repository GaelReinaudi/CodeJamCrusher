import reaction as solver
from pyinstrument import Profiler

if __name__ == "__main__":
    INPUT_LINES = (
        """

6
1
111
0
2
111 222
0 0
2
111 222
0 1
4
60 20 40 50
0 1 1 2
5
3 2 1 4 5
0 1 1 1 0
8
100 100 100 90 80 100 90 100
0 1 2 1 2 3 1 3


"""

#         + (
#             """
# 800
# """
#             + "100 100 100 90 80 100 90 100 " * 100
#             + "\n"
#             + "0 1 2 1 2 3 1 3 " * 100
#         )
#         * 100

    )
    
    INPUT_LINES = INPUT_LINES.splitlines()
    INPUT_LINES = [line for line in INPUT_LINES if line]
    OUTPUT_LINES = """

Case #1: 111
Case #2: 333
Case #3: 222
Case #4: 110
Case #5: 14
Case #6: 490


""".splitlines()
    OUTPUT_LINES = [line for line in OUTPUT_LINES if line]


p1 = Profiler()
with p1:
    solver.run(
        INPUT_LINES=list(INPUT_LINES),
        OUTPUT_LINES=list(OUTPUT_LINES),
    )

# p2 = Profiler()
# with p2:
#     solver.run_parallel(
#         INPUT_LINES=list(INPUT_LINES),
#         OUTPUT_LINES=list(OUTPUT_LINES),
#     )

p1.print(show_all=False)
# p2.print(show_all=False)
