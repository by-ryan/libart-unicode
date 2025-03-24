#ifndef art__unicode__decoder_hxx_
#define art__unicode__decoder_hxx_

#include <cstddef>
#include <cstdint>
#include <iterator>

namespace art::unicode
{

  constexpr uint32_t const replacement_character{0xFFFD};

  class decoder_t
  {
  public:
    virtual
    ~decoder_t() noexcept;

    class iterator_t;
    friend iterator_t;

    iterator_t
    begin();

    iterator_t
    end();

    virtual
    uint32_t
    decode() = 0;

  protected:
    /// Constructor.
    ///
    decoder_t();

    /// Copy-construction is prohibited.
    ///
    decoder_t(decoder_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    decoder_t(decoder_t&&) = delete;

    virtual
    bool
    at_end() = 0;

    /// Copy-assignment is prohibited.
    ///
    decoder_t&
    operator=(decoder_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    decoder_t&
    operator=(decoder_t&&) = delete;

  };

  /// Decoder iterator.
  ///
  class decoder_t::iterator_t
  {
  public:
    using value_type = uint32_t;
    using pointer = uint32_t const*;
    using reference = uint32_t const&;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::input_iterator_tag;

    /// Constructor.
    ///
    iterator_t() = default;

    /// Constructor.
    ///
    iterator_t(iterator_t const&) = default;

    /// Constructor.
    ///
    iterator_t(iterator_t&&) = default;

    /// Destructor.
    ///
    ~iterator_t() noexcept = default;

    /// Assignment.
    ///
    iterator_t&
    operator=(iterator_t const&) = default;

    /// Assignment.
    ///
    iterator_t&
    operator=(iterator_t&&) = default;

    reference
    operator*() const
    {
      return _codepoint;
    }

    pointer
    operator->() const
    {
      return &_codepoint;
    }

    iterator_t&
    operator++()
    {
      next();
      return *this;
    }

    /// Compare equality.
    ///
    bool
    operator==(iterator_t const& other) const
    {
      return _decoder == other._decoder;
    }

    /// Compare inequality.
    ///
    bool
    operator!=(iterator_t const& other) const
    {
      return !(*this == other);
    }

  private:
    friend decoder_t;

    iterator_t(decoder_t* d)
      : _decoder{d}
    {
      next();
    }

    void
    next()
    {
      if (_decoder->at_end()) {
        _decoder = nullptr;
      }
      else {
        _codepoint = _decoder->decode();
      }
    }

    decoder_t* _decoder{};
    uint32_t _codepoint;

  };

} // namespace art::unicode

#endif
