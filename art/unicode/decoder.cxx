#include <art/unicode/decoder.hxx>

namespace art::unicode
{

  decoder_t::
  ~decoder_t() noexcept
  {}

  decoder_t::iterator_t
  decoder_t::
  begin()
  {
    return iterator_t{this};
  }

  decoder_t::iterator_t
  decoder_t::
  end()
  {
    return iterator_t{};
  }

  decoder_t::
  decoder_t()
  {}

} // namespace art::unicode
