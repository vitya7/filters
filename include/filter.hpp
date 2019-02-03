#pragma once

#include <cmath>
#include <type_traits>

namespace filters
{
    template <class T, class F>
    class filter
    {
    public :

        using value_type = T;
        using func_type = F;
        using result_type = std::invoke_result_t <func_type, value_type>;

        explicit
        filter ( value_type center = value_type (0)
               , value_type width  = value_type (1)
               , func_type  func   = func_type  () );

        result_type operator () (value_type) const;

        value_type  get_center  () const;
        value_type  get_width   () const;
        func_type   get_func    () const;

        void        set_center  (value_type);
        void        set_width   (value_type);
        void        set_func    (func_type);

        template <class Tp, class Func>
        filter &    operator =  (filter <Tp, Func>);


        template <class Tp, class Func>
        friend class filter;

    private :

        value_type m_center;
        value_type m_width;

        func_type m_func;
    };

}

namespace filters
{
    template <class T, class F>
    filter <T, F>::
    filter ( value_type center
           , value_type width
           , func_type  func )
        :
            m_center ( center )
        ,   m_width  ( width )
        ,   m_func   ( std::move( func ) )
    {}

    template <class T, class F>
    typename filter <T, F> :: result_type
    filter <T, F>::
    operator () (value_type x) const
    {
        return m_func( ( x - m_center ) / m_width );
    }

    template <class T, class F>
    typename filter <T, F> :: value_type
    filter <T, F>::
    get_center () const
    {
        return m_center;
    }

    template <class T, class F>
    typename filter <T, F> :: value_type
    filter <T, F>::
    get_width () const
    {
        return m_width;
    }

    template <class T, class F>
    typename filter <T, F> :: func_type
    filter <T, F>::
    get_func () const
    {
        return m_func;
    }

    template <class T, class F>
    void
    filter <T, F>::
    set_center (value_type val)
    {
        m_center = val;
    }

    template <class T, class F>
    void
    filter <T, F>::
    set_width (value_type val)
    {
        m_width = val;
    }


    template <class T, class F>
    void
    filter <T, F>::
    set_func (func_type func)
    {
        m_func = std::move( func );
    }

    template <class T, class F>
    template <class Tp, class Func>
    filter <T, F> &
    filter <T, F>::
    operator = (filter <Tp, Func> f)
    {
        m_center = f.m_center;
        m_width = f.m_width;

        m_func = std::move( f.m_func );

        return *this;
    }
}
