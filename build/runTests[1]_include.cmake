if(EXISTS "/Users/lucyhadden/COSC345/build/runTests[1]_tests.cmake")
  include("/Users/lucyhadden/COSC345/build/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()
