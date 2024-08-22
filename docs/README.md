# COSC345
COSC345 Group project (software engineering)

# Important if pipeline doesn't pass!
if the pipeline is not passing, this could be a problem because you haven't deleted your build-coverage directory, ensure that before you push you delete build-coverage

# Build and run main program instructions 
if you want to run the program, i.e. the main game follow the steps below (only do the following the first time you compile the make file)

1. from the COSC345 directory, mkdir build-coverage,  cd build-coverage
2. run cmake -DCMAKE_BUILD_TYPE=Coverage .. (the .. references the CMakeList.txt file in the root (COSC345) directory)
3. run 'make'
4. run ./COSC345


i.e. 
1. mkdir build-coverage
2. cd build-coverage
3. cmake -DCMAKE_BUILD_TYPE=Coverage ..
4. make
5. ./COSC345

# Code coverage instructions

the code coverage is ran via the yaml file (Codecov.yml), if you want to generate the report, you just need to push your changes to the origin, then look at github actions
you will see a manual compilation of the tests that have been ran. If you want to view them via a gui format then log into the CodeCov website

-- make sure before you do this that you have DELETED the build-coverage directory!s
1. commit and push changes
2. github actions
3. under the 'generate code cov' view the manual report generated
4. view it in gui format via CodeCov website (https://app.codecov.io/gh/lucyhadden/COSC345)

