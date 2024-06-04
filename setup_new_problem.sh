#!/bin/bash

echo "Setting up a new problem directory"
echo "Problem No. ?"
read -r problem_number

echo "Problem Domain ? (HR: HackerRank, CSES: CSES, LC: LeetCode, CF: CodeChef)"
read -r problem_domain

echo "Problem ID on the domain ?"
read -r problem_id

problem_dir="Problems/${problem_number}_${problem_domain}_${problem_id}/"
echo "Create problem directory: \"$problem_dir\" ? (y/Y: Yes, N/n: no)"
read -r should_create

if [[ "$should_create" != y ]] && [[ "$should_create" != Y ]]; then
    echo "User input declines creation, exiting..."
    exit
fi

echo "Creating problem Directory"
mkdir -p "${problem_dir}"

echo "Copying Template.cpp"
cp Template.cpp "${problem_dir}problem.cpp"

echo "Creating input.txt and output.txt"
touch "${problem_dir}input.txt"
touch "${problem_dir}output.txt"

echo "Creating compile_and_run.sh"
touch "${problem_dir}compile_and_run.sh"

echo "Defining compile_and_run.sh"
cat >>"${problem_dir}compile_and_run.sh" <<'END'
#!/bin/bash
echo "Getting env variable"
env_var=$(<../../.env)
export "${env_var?}"=true
clang++ problem.cpp -o problem -std=c++20 && problem.exe
END
echo "compile_and_run.sh created successfully"

echo "New problem setup complete"
echo "Open ${problem_dir}problem.cpp and start editing!"
exit
