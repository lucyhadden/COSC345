# COSC345
COSC345 Group project (software engineering)

## Badges
[![codecov](https://codecov.io/gh/lucyhadden/COSC345/graph/badge.svg?token=2VWHP87OID)](https://codecov.io/gh/lucyhadden/COSC345)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/f5370b6729b1493bbddd74b639dfa4cb)](https://app.codacy.com/gh/lucyhadden/COSC345/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
![Documentation](https://img.shields.io/badge/documentation-doxygen-blue)
![GitHub forks](https://img.shields.io/github/forks/lucyhadden/COSC345.svg?style=social)
![GitHub pull requests](https://img.shields.io/github/issues-pr/lucyhadden/COSC345.svg)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/lucyhadden/COSC345.svg)
![GitHub last commit](https://img.shields.io/github/last-commit/lucyhadden/COSC345.svg)
![GitHub top language](https://img.shields.io/github/languages/top/lucyhadden/COSC345.svg)
[![CodeQL](https://github.com/lucyhadden/COSC345/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/lucyhadden/COSC345/actions/workflows/github-code-scanning/codeql)



# Important if pipeline doesn't pass!
if the pipeline is not passing, this could be a problem because you haven't deleted your build-coverage directory, ensure that before you push you delete build-coverage

# Build and run main program instructions 
if you want to run the program, i.e. the main game follow the steps below (only do the following the first time you compile the make file)

1. from the COSC345 directory, mkdir build-coverage,  cd build-coverage
2. run cmake -DCMAKE_BUILD_TYPE=Coverage .. (the .. references the CMakeList.txt file in the root (COSC345) directory)
3. run 'make'
4. run ./COSC345


i.e. On Mac/Linux
1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./COSC345

On Windows
1. mkdir build
2. cmake -B build
3. cmake --build build
4. ./build/Debug/COSC345.exe

# Code coverage instructions

the code coverage is ran via the yaml file (Codecov.yml), if you want to generate the report, you just need to push your changes to the origin, then look at github actions
you will see a manual compilation of the tests that have been ran. If you want to view them via a gui format then log into the CodeCov website

-- make sure before you do this that you have DELETED the build-coverage directory!s
1. commit and push changes
2. github actions
3. under the 'generate code cov' view the manual report generated
4. view it in gui format via CodeCov website (https://app.codecov.io/gh/lucyhadden/COSC345)

codeacy link
https://app.codacy.com/gh/lucyhadden/COSC345/dashboard 

codedocs link
https://codedocs.xyz/lucyhadden/COSC345/files.html