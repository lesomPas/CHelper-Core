//
// Created by Yancey on 2023/11/7.
//

#include <chelper/resources/id/NormalId.h>

namespace CHelper {

    void NormalId::buildHash() {
        if (HEDLEY_UNLIKELY(!isBuildHash)) {
            isBuildHash = true;
            nameHash = std::hash<std::u16string>{}(name);
            mHashCode = std::hash<std::u16string>{}(name);
        }
    }

    [[nodiscard]] bool NormalId::fastMatch(size_t strHash) {
        buildHash();
        return nameHash == strHash;
    }

    [[nodiscard]] size_t NormalId::hashCode() {
        buildHash();
        return mHashCode;
    }

    std::shared_ptr<NormalId> NormalId::make(const std::u16string &name, const std::optional<std::u16string> &description) {
        auto result = std::make_shared<NormalId>();
        result->name = name;
        result->description = description;
        return result;
    }

}// namespace CHelper