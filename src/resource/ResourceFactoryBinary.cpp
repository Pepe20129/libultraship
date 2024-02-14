#include "ResourceFactoryBinary.h"
#include <variant>
#include "spdlog/spdlog.h"

namespace LUS {
bool ResourceFactoryBinary::FileHasValidFormatAndReader(std::shared_ptr<File> file) {
    if (file->InitData->Format != RESOURCE_FORMAT_BINARY) {
        SPDLOG_ERROR("resource file format does not match factory format.");
        return false;
    }

    if (!std::holds_alternative<std::shared_ptr<BinaryReader>>(file->Reader)) {
        SPDLOG_ERROR("Failed to load resource: File has Reader ({} - {})", file->InitData->Type, file->InitData->Path);
        return false;
    }

    return true;
};
} // namespace LUS
