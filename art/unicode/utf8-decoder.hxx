#ifndef art__unicode__utf8_decoder_hxx_
#define art__unicode__utf8_decoder_hxx_

#include <art/unicode/decoder.hxx>
#include <art/unicode/reader.hxx>

namespace art::unicode
{

  /// UTF-8 decoder.
  ///
  class utf8_decoder_t
    : public decoder_t
  {
  public:
    /// Constructor.
    ///
    explicit
    utf8_decoder_t(reader_t&);

    /// Copy-construction is prohibited.
    ///
    utf8_decoder_t(utf8_decoder_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    utf8_decoder_t(utf8_decoder_t&&) = delete;

    uint32_t
    decode() override;

    /// Copy-assignment is prohibited.
    ///
    utf8_decoder_t&
    operator=(utf8_decoder_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    utf8_decoder_t&
    operator=(utf8_decoder_t&&) = delete;

  protected:
    bool
    at_end() override;

  private:
    reader_t& _reader;

  };

} // namespace art::unicode

#endif
