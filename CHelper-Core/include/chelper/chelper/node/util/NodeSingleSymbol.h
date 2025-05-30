//
// Created by Yancey on 2023/12/19.
//

#pragma once

#ifndef CHELPER_NODESINGLESYMBOL_H
#define CHELPER_NODESINGLESYMBOL_H


#include "../NodeBase.h"

namespace CHelper::Node {

    class NodeSingleSymbol : public NodeBase {
    public:
        char16_t symbol = ' ';
        std::shared_ptr<NormalId> normalId;
        bool isAddWhitespace = false;

        NodeSingleSymbol() = default;

        NodeSingleSymbol(const std::optional<std::u16string> &id,
                         const std::optional<std::u16string> &description,
                         char16_t symbol,
                         bool isAddWhitespace = true);

        [[nodiscard]] NodeTypeId::NodeTypeId getNodeType() const override;

        ASTNode getASTNode(TokenReader &tokenReader, const CPack *cpack) const override;

        bool collectSuggestions(const ASTNode *astNode,
                                size_t index,
                                std::vector<Suggestions> &suggestions) const override;

        bool collectColor(const ASTNode *astNode,
                          ColoredString &coloredString,
                          const Theme &theme) const override;
    };

}// namespace CHelper::Node


#endif//CHELPER_NODESINGLESYMBOL_H
