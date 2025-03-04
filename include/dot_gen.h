#pragma once
#include "CVisitor.h"
#include "regtab.h"
#include <any>
#include <iostream>
#include <ostream>
namespace KTC{
    //vim 操作
    //q开始记录宏 --qq 开启绑定q为宏
    // --/  搜索   f 行内搜索单字符
    // --n 搜索到下一个(/)  --N 上
    // v选择模式
    // j 下 k 上 h左 l右
    // vaw 选择一个词
    // a光标后输入 ，i 插入  o 下一行输入 shift i 行首 shift a 行末尾 $ 0
    // p 粘贴  y 复制
    // x删除
    // g行  gg首行 G末尾 3g 第三行 
    //@_ 调用宏  2@_  u撤销 
    // bb删除整行
    class MyCVisitor:CVisitor{
    public:
    std::ostringstream oss;
    MyCVisitor():oss(){}
    virtual std::any visitPrimaryExpression(CParser::PrimaryExpressionContext *context) {
        oss<<"PrimaryExpression";
        return nullptr;
    }
    virtual std::any visitGenericSelection(CParser::GenericSelectionContext *context) {
        oss<<"GenericSelection";
        return nullptr;
    }

    virtual std::any visitGenericAssocList(CParser::GenericAssocListContext *context) {
        oss<<"GenericAssocList";
        return nullptr;
    }

    virtual std::any visitGenericAssociation(CParser::GenericAssociationContext *context) {
        oss<<"GenericAssociation";
        return nullptr;
    }

    virtual std::any visitPostfixExpression(CParser::PostfixExpressionContext *context) {
        oss<<"PostfixExpression";
        return nullptr;
    }

    virtual std::any visitArgumentExpressionList(CParser::ArgumentExpressionListContext *context) {
        oss<<"ArgumentExpressionList";
        return nullptr;
    }

    virtual std::any visitUnaryExpression(CParser::UnaryExpressionContext *context) {
        oss<<"UnaryExpression";
        return nullptr;
    }

    virtual std::any visitUnaryOperator(CParser::UnaryOperatorContext *context) {
        oss<<"UnaryOperator";
        return nullptr;
    }

    virtual std::any visitCastExpression(CParser::CastExpressionContext *context) {
        oss<<"CastExpression";
        return nullptr;
    }

    virtual std::any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *context) {
        oss<<"MultiplicativeExpression";
        return nullptr;
    }

    virtual std::any visitAdditiveExpression(CParser::AdditiveExpressionContext *context) {
        oss<<"AdditiveExpression";
        return nullptr;
    }

    virtual std::any visitShiftExpression(CParser::ShiftExpressionContext *context) {
        oss<<"ShiftExpression";
        return nullptr;
    }

    virtual std::any visitRelationalExpression(CParser::RelationalExpressionContext *context) {
        oss<<"RelationalExpression";
        return nullptr;
    }

    virtual std::any visitEqualityExpression(CParser::EqualityExpressionContext *context) {
        oss<<"EqualityExpression";
        return nullptr;
    }

    virtual std::any visitAndExpression(CParser::AndExpressionContext *context) {
        oss<<"AndExpression";
        return nullptr;
    }

    virtual std::any visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *context) {
        oss<<"ExclusiveOrExpression";
        return nullptr;
    }

    virtual std::any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *context) {
        oss<<"InclusiveOrExpression";
        return nullptr;
    }

    virtual std::any visitLogicalAndExpression(CParser::LogicalAndExpressionContext *context) {
        oss<<"LogicalAndExpression";
        return nullptr;
    }

    virtual std::any visitLogicalOrExpression(CParser::LogicalOrExpressionContext *context) {
        oss<<"LogicalOrExpression";
        return nullptr;
    }

    virtual std::any visitConditionalExpression(CParser::ConditionalExpressionContext *context) {
        oss<<"ConditionalExpression";
        return nullptr;
    }

    virtual std::any visitAssignmentExpression(CParser::AssignmentExpressionContext *context) {
        oss<<"AssignmentExpression";
        return nullptr;
    }

    virtual std::any visitAssignmentOperator(CParser::AssignmentOperatorContext *context) {
        oss<<"AssignmentOperator";
        return nullptr;
    }

    virtual std::any visitExpression(CParser::ExpressionContext *context) {
        oss<<"Expression";
        return nullptr;
    }

    virtual std::any visitConstantExpression(CParser::ConstantExpressionContext *context) {
        oss<<"ConstantExpression";
        return nullptr;
    }

    virtual std::any visitDeclaration(CParser::DeclarationContext *context) {
        oss<<"Declaration";
        return nullptr;
    }

    virtual std::any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *context) {
        oss<<"DeclarationSpecifiers";
        return nullptr;
    }

    virtual std::any visitDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context *context) {
        oss<<"DeclarationSpecifiers2";
        return nullptr;
    }

    virtual std::any visitDeclarationSpecifier(CParser::DeclarationSpecifierContext *context) {
        oss<<"DeclarationSpecifier";
        return nullptr;
    }

    virtual std::any visitInitDeclaratorList(CParser::InitDeclaratorListContext *context) {
        oss<<"InitDeclaratorList";
        return nullptr;
    }

    virtual std::any visitInitDeclarator(CParser::InitDeclaratorContext *context) {
        oss<<"InitDeclarator";
        return nullptr;
    }

    virtual std::any visitStorageClassSpecifier(CParser::StorageClassSpecifierContext *context) {
        oss<<"StorageClassSpecifier";
        return nullptr;
    }

    virtual std::any visitTypeSpecifier(CParser::TypeSpecifierContext *context) {
        oss<<"TypeSpecifier";
        return nullptr;
    }

    virtual std::any visitStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext *context) {
        oss<<"StructOrUnionSpecifier";
        return nullptr;
    }

    virtual std::any visitStructOrUnion(CParser::StructOrUnionContext *context) {
        oss<<"StructOrUnion";
        return nullptr;
    }

    virtual std::any visitStructDeclarationList(CParser::StructDeclarationListContext *context) {
        oss<<"StructDeclarationList";
        return nullptr;
    }

    virtual std::any visitStructDeclaration(CParser::StructDeclarationContext *context) {
        oss<<"StructDeclaration";
        return nullptr;
    }

    virtual std::any visitSpecifierQualifierList(CParser::SpecifierQualifierListContext *context) {
        oss<<"SpecifierQualifierList";
        return nullptr;
    }

    virtual std::any visitStructDeclaratorList(CParser::StructDeclaratorListContext *context) {
        oss<<"StructDeclaratorList";
        return nullptr;
    }

    virtual std::any visitStructDeclarator(CParser::StructDeclaratorContext *context) {
        oss<<"StructDeclarator";
        return nullptr;
    }

    virtual std::any visitEnumSpecifier(CParser::EnumSpecifierContext *context) {
        oss<<"EnumSpecifier";
        return nullptr;
    }

    virtual std::any visitEnumeratorList(CParser::EnumeratorListContext *context) {
        oss<<"EnumeratorList";
        return nullptr;
    }

    virtual std::any visitEnumerator(CParser::EnumeratorContext *context) {
        oss<<"Enumerator";
        return nullptr;
    }

    virtual std::any visitEnumerationConstant(CParser::EnumerationConstantContext *context) {
        oss<<"EnumerationConstant";
        return nullptr;
    }

    virtual std::any visitAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext *context) {
        oss<<"AtomicTypeSpecifier";
        return nullptr;
    }

    virtual std::any visitTypeQualifier(CParser::TypeQualifierContext *context) {
        oss<<"TypeQualifier";
        return nullptr;
    }

    virtual std::any visitFunctionSpecifier(CParser::FunctionSpecifierContext *context) {
        oss<<"isitFunctionSpecifier";
        return nullptr;
    }

    virtual std::any visitAlignmentSpecifier(CParser::AlignmentSpecifierContext *context) {
        oss<<"AlignmentSpecifier";
        return nullptr;
    }

    virtual std::any visitDeclarator(CParser::DeclaratorContext *context) {
        oss<<"Declarator";
        return nullptr;
    }

    virtual std::any visitDirectDeclarator(CParser::DirectDeclaratorContext *context) {
        oss<<"DirectDeclarator";
        return nullptr;
    }

    virtual std::any visitVcSpecificModifer(CParser::VcSpecificModiferContext *context) {
        oss<<"VcSpecificModifer";
        return nullptr;
    }

    virtual std::any visitNestedParenthesesBlock(CParser::NestedParenthesesBlockContext *context) {
        oss<<"NestedParenthesesBlock";
        return nullptr;
    }

    virtual std::any visitPointer(CParser::PointerContext *context) {
        oss<<"Pointer";
        return nullptr;
    }

    virtual std::any visitTypeQualifierList(CParser::TypeQualifierListContext *context) {
        oss<<"TypeQualifierList";
        return nullptr;
    }

    virtual std::any visitParameterTypeList(CParser::ParameterTypeListContext *context) {
        oss<<"ParameterTypeList";
        return nullptr;
    }

    virtual std::any visitParameterList(CParser::ParameterListContext *context) {
        oss<<"ParameterList";
        return nullptr;
    }

    virtual std::any visitParameterDeclaration(CParser::ParameterDeclarationContext *context) {
        oss<<"ParameterDeclaration";
        return nullptr;
    }

    virtual std::any visitIdentifierList(CParser::IdentifierListContext *context) {
        oss<<"IdentifierList";
        return nullptr;
    }

    virtual std::any visitTypeName(CParser::TypeNameContext *context) {
        oss<<"TypeName";
        return nullptr;
    }

    virtual std::any visitAbstractDeclarator(CParser::AbstractDeclaratorContext *context) {
        oss<<"AbstractDeclarator";
        return nullptr;
    }

    virtual std::any visitDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext *context) {
        oss<<"DirectAbstractDeclarator";
        return nullptr;
    }

    virtual std::any visitTypedefName(CParser::TypedefNameContext *context) {
        oss<<"TypedefName";
        return nullptr;
    }

    virtual std::any visitInitializer(CParser::InitializerContext *context) {
        oss<<"Initializer";
        return nullptr;
    }

    virtual std::any visitInitializerList(CParser::InitializerListContext *context) {
        oss<<"InitializerList";
        return nullptr;
    }

    virtual std::any visitDesignation(CParser::DesignationContext *context) {
        oss<<"Designation";
        return nullptr;
    }

    virtual std::any visitDesignatorList(CParser::DesignatorListContext *context) {
        oss<<"DesignatorList";
        return nullptr;
    }

    virtual std::any visitDesignator(CParser::DesignatorContext *context) {
        oss<<"Designator";
        return nullptr;
    }

    virtual std::any visitStaticAssertDeclaration(CParser::StaticAssertDeclarationContext *context) {
        oss<<"StaticAssertDeclaration";
        return nullptr;
    }

    virtual std::any visitStatement(CParser::StatementContext *context) {
        oss<<"Statement";
        return nullptr;
    }

    virtual std::any visitLabeledStatement(CParser::LabeledStatementContext *context) {
        oss<<"LabeledStatement";
        return nullptr;
    }

    virtual std::any visitCompoundStatement(CParser::CompoundStatementContext *context) {
        oss<<"CompoundStatement";
        return nullptr;
    }

    virtual std::any visitBlockItemList(CParser::BlockItemListContext *context) {
        oss<<"BlockItemList";
        return nullptr;
    }

    virtual std::any visitBlockItem(CParser::BlockItemContext *context) {
        oss<<"BlockItem";
        return nullptr;
    }

    virtual std::any visitExpressionStatement(CParser::ExpressionStatementContext *context) {
        oss<<"ExpressionStatement";
        return nullptr;
    }

    virtual std::any visitSelectionStatement(CParser::SelectionStatementContext *context) {
        oss<<"SelectionStatement";
        return nullptr;
    }

    virtual std::any visitIfSelection(CParser::IfSelectionContext *context) {
        oss<<"IfSelection";
        return nullptr;
    }

    virtual std::any visitSwitchSelection(CParser::SwitchSelectionContext *context) {
        oss<<"SwitchSelection";
        return nullptr;
    }

    virtual std::any visitIterationStatement(CParser::IterationStatementContext *context) {
        oss<<"IterationStatement";
        return nullptr;
    }

    virtual std::any visitForIterationStatement(CParser::ForIterationStatementContext *context) {
        oss<<"ForIterationStatement";
        return nullptr;
    }

    virtual std::any visitWhileIterationStatement(CParser::WhileIterationStatementContext *context) {
        oss<<"WhileIterationStatement";
        return nullptr;
    }

    virtual std::any visitDoWhileIterationStatement(CParser::DoWhileIterationStatementContext *context) {
        oss<<"DoWhileIterationStatement";
        return nullptr;
    }

    virtual std::any visitForCondition(CParser::ForConditionContext *context) {
        oss<<"ForCondition";
        return nullptr;
    }

    virtual std::any visitForDeclaration(CParser::ForDeclarationContext *context) {
        oss<<"ForDeclaration";
        return nullptr;
    }

    virtual std::any visitForBeforeExpression(CParser::ForBeforeExpressionContext *context) {
        oss<<"ForBeforeExpression";
        return nullptr;
    }

    virtual std::any visitForAfterExpression(CParser::ForAfterExpressionContext *context) {
        oss<<"ForAfterExpression";
        return nullptr;
    }

    virtual std::any visitForMidExpression(CParser::ForMidExpressionContext *context) {
        oss<<"ForMidExpression";
        return nullptr;
    }

    virtual std::any visitJumpStatement(CParser::JumpStatementContext *context) {
        oss<<"JumpStatement";
        return nullptr;
    }

    virtual std::any visitBreakpointStatement(CParser::BreakpointStatementContext *context) {
        oss<<"BreakpointStatement";
        return nullptr;
    }

    virtual std::any visitBreakpointArg(CParser::BreakpointArgContext *context) {
        oss<<"BreakpointArg";
        return nullptr;
    }

    virtual std::any visitContinueStatement(CParser::ContinueStatementContext *context) {
        oss<<"ContinueStatement";
        return nullptr;
    }

    virtual std::any visitBreakStatement(CParser::BreakStatementContext *context) {
        oss<<"BreakStatement";
        return nullptr;
    }

    virtual std::any visitReturnStatement(CParser::ReturnStatementContext *context) {
        oss<<"ReturnStatement";
        return nullptr;
    }

    virtual std::any visitCompilationUnit(CParser::CompilationUnitContext *context) {
        oss<<"CompilationUnit";
        return nullptr;
    }

    virtual std::any visitTranslationUnit(CParser::TranslationUnitContext *context) {
        oss<<"TranslationUnit";
        return nullptr;
    }

    virtual std::any visitExternalDeclaration(CParser::ExternalDeclarationContext *context) {
        oss<<"ExternalDeclaration";
        return nullptr;
    }

    virtual std::any visitFunctionDefinition(CParser::FunctionDefinitionContext *context) {
        oss<<"FunctionDefinition";
        return nullptr;
    }

    virtual std::any visitDeclarationList(CParser::DeclarationListContext *context) {
        oss<<"DeclarationList";
        return nullptr;
    }
    
};

}