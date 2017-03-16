// Project includes
#include "clang-expand/common/call-data.hpp"

// Standard includes
#include <optional>
#include <type_traits>

namespace ClangExpand {
CallData::CallData(AssigneeData&& assignee, Range&& extent_)
: assignee(std::move(assignee)), extent(extent_) {
}

CallData::CallData(Range&& extent_) : extent(extent_) {
}

bool CallData::requiresDeclaration() const noexcept {
  return assignee.has_value() && assignee->type.has_value();
}

}  // namespace ClangExpand
