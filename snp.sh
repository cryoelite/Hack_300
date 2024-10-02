#!/bin/bash
#setup_new_problem.sh
#To execute, simply do ./snp.sh <url of the problem>

echo "Setting up a new problem directory"

problem_url=$1

# Extract problem_domain and problem_name using sed
problem_domain=$(echo "$problem_url" | sed -E 's|https://([^\.]+).*|\1|' | tr '[:upper:]' '[:lower:]')
problem_name=$(echo "$problem_url" | sed -E 's|.*/problems/([^/]+)$|\1|' | tr '[:upper:]' '[:lower:]')

#Get the problem number
current_problem_count=$(ls -l Problems/ | grep -c ^d)
problem_number=$(($current_problem_count + 1))

problem_domain_shortcode=$problem_domain
if [ "$problem_domain" == leetcode ] || [ "$problem_domain" == neetcode ]; then
    problem_domain_shortcode=LC
fi
if [ "$problem_domain" == hackerrank ]; then
    problem_domain_shortcode=HR
fi

echo "Problem domain: $problem_domain"
echo "Problem domain shortcode: $problem_domain_shortcode"
echo "Problem name: $problem_name"
echo "Problem number: $problem_number"

problem_dir="Problems/${problem_number}_${problem_domain_shortcode}_${problem_name}/"
echo "Creating problem directory: \"$problem_dir\""

if [ -d "$problem_dir" ]; then
    echo "$problem_dir already exists, exiting...."
    exit
else
    echo "Creating problem Directory"
    mkdir -p "${problem_dir}"
fi

if [[ "$problem_domain_shortcode" == LC ]]; then
    echo "Copying Template_LC.cpp"
    cp Template_LC.cpp "${problem_dir}problem.cpp"
else
    echo "Copying Template.cpp"
    cp Template.cpp "${problem_dir}problem.cpp"
fi

echo "Modifying problem.cpp to contain the problem URL"
sed -i "1s|.*|// $problem_url|" "${problem_dir}problem.cpp"

echo "Creating input.txt, output.txt and solution.md"
touch "${problem_dir}input.txt"
touch "${problem_dir}output.txt"
touch "${problem_dir}solution.md"

echo "Creating car.sh (alias for compile_and_run)"
touch "${problem_dir}car.sh"

echo "Defining car.sh"
cat >>"${problem_dir}car.sh" <<'END'
#!/bin/bash
#compile_and_run.sh
echo "Getting env variable"
env_var=$(<../../.env)
export "${env_var?}"=true
clang++ problem.cpp -o problem -std=c++20 && ./problem
END
echo "car.sh created successfully"

echo "Git updating with current problem (if git is setup)"
git add .
git commit -m "Probelm ${problem_number} ${problem_name} setup and old problems committed"
git push

echo "New problem setup complete"
echo "Open ${problem_dir}problem.cpp and start editing!"
