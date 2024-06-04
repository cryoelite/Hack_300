# Hack_300
300 problems 60 days

Requirements:
> clang compiler

Run setup_new_problem.sh with ``./setup_new_problem.sh`` in bash to setup a new problem directory with the Template.cpp file and a compile script in it
Modify problem.cpp in the new directory 
Run ``./compile_and_run.sh``

Optional:
> Every ``problem.cpp`` relies on an environment variable defined in ``.env``, if the ``.env``file exists, and the environment variable in it is set with a value of true then local mode is started for the program.

Local Mode:
Local mode in ``problem.cpp`` simply uses ``input.txt`` and ``output.txt`` files in the problem directory for input/output. 
Enabled either through the environment variable defined in ``.env`` to be true or if the ForceLOCAL macro is set in ``problem.cpp``

