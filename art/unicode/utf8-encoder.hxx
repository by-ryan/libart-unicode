#ifndef art__unicode__utf8_encoder_hxx_
#define art__unicode__utf8_encoder_hxx_

#include <art/unicode/encoder.hxx>
#include <art/unicode/writer.hxx>

namespace art::unicode
{

  class utf8_encoder_t
    : public encoder_t
  {
  public:
    /// Constructor.
    ///
    explicit
    utf8_encoder_t(writer_t&);

    /// Copy-construction is prohibited.
    ///
    utf8_encoder_t(utf8_encoder_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    utf8_encoder_t(utf8_encoder_t&&) = delete;

    /// Encode Unicode code point.
    ///
    void
    encode(uint32_t) override;

    /// Copy-assignment is prohibited.
    ///
    utf8_encoder_t&
    operator=(utf8_encoder_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    utf8_encoder_t&
    operator=(utf8_encoder_t&&) = delete;

  private:
    writer_t& _writer;

  };

} // namespace art::unicode

#endif
