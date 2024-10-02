# Hack_300
300 problems 60 days

# Requirements:
* clang

# How To Use:
* Run ``snp.sh`` with ``./snp.sh`` in bash to setup a new problem directory with the ``Template.cpp`` file and a generated compile script in it
* Modify ``input.txt`` with input for the problem (only used in local mode)
* Modify ``problem.cpp`` in the new directory 
* Run ``./car.sh`` to automatically define local mode environment variable and execute ``problem.cpp``
* Examine output.txt
* Profit ✨

# Optional:
* Every ``problem.cpp`` relies on an environment variable defined in ``.env``, if the ``.env``file exists, and the environment variable in it is set with a value of `true` then local mode is started for the program. You can directly modify the variable in it to whatever you like or leave it as is. It is stored in base ``./`` relative directory as ``./.env``.
Example ``.env`` file contents:
```
local_mode=true
```
where ``local_mode`` is the environment variable and its value is ``true``, defined with ``=``.
* Define problem url at line 1 of a ``problem.cpp`` for easy problem statement access.
* Use ``Test.cpp`` to quickly test out some code.

# Local Mode:
* Local mode in ``problem.cpp`` simply uses ``input.txt`` and ``output.txt`` files in the problem directory for input/output. 
Enabled either through the environment variable defined in ``.env`` to be true or if the ForceLOCAL macro is set in ``problem.cpp``

# FAQ
* What's ``snp.sh`` and ``car.sh`` ?
- ``snp`` is alias for ``setup_new_problem`` and ``car`` is alias for ``compile_and_run``
The names are aliased for quicker use in the cli.

