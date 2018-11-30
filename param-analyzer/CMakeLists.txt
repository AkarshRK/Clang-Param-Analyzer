set(LLVM_LINK_COMPONENTS support)

add_clang_executable(param-analyzer
  ParamAnalyzer.cpp
  )
target_link_libraries(param-analyzer
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  )
