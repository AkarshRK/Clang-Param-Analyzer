#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/CommonOptionsParser.h"

#include "llvm/Support/CommandLine.h"

using namespace clang;
using namespace llvm;
using namespace clang::tooling;

static llvm::cl::OptionCategory MyToolCategory("my-tool options");

class FuncParameterAnalyzerVisitor
  : public RecursiveASTVisitor<FuncParameterAnalyzerVisitor> {
public:
  explicit FuncParameterAnalyzerVisitor(ASTContext *Context)
    : Context(Context) {}

  bool VisitFunctionDecl(FunctionDecl *func) {
        std::string funcName = func->getNameInfo().getName().getAsString();
        if(func->getNumParams() > 3) {
        llvm::outs() << "<---Warning--->\n" << "\"" << funcName << "\"" << " has more than three parameters. "<<"\n";
        }
        
        return true;
    }

private:
  ASTContext *Context;
};

class FuncParameterAnalyzerConsumer : public clang::ASTConsumer {
public:
  explicit FuncParameterAnalyzerConsumer(ASTContext *Context)
    : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  FuncParameterAnalyzerVisitor Visitor;
};

class FuncParameterAnalyzerAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::unique_ptr<clang::ASTConsumer>(
        new FuncParameterAnalyzerConsumer(&Compiler.getASTContext()));
  }
};

int main(int argc, const char **argv) {

  CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
  ClangTool Tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());
  return Tool.run(newFrontendActionFactory<FuncParameterAnalyzerAction>().get());

}
