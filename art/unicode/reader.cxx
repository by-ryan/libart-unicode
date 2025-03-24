#include <art/unicode/reader.hxx>

namespace art::unicode
{

  reader_t::
  ~reader_t() noexcept
  {}

  std::uint8_t
  reader_t::
  advance()
  {
    auto byte = get();
    next();
    return byte;
  }

  reader_t::
  reader_t()
  {}

} // namespace art::unicode
