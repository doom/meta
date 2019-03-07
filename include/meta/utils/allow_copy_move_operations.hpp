/*
** Created by doom on 06/03/19.
*/

#ifndef META_UTILS_ALLOW_COPY_MOVE_OPERATIONS_HPP
#define META_UTILS_ALLOW_COPY_MOVE_OPERATIONS_HPP

namespace meta
{
    template <typename T, bool>
    class allow_move_construction_if : public T
    {
    public:
        using T::T;

        constexpr allow_move_construction_if() = default;

        allow_move_construction_if(const allow_move_construction_if &) = default;

        allow_move_construction_if(allow_move_construction_if &&) = default;

        allow_move_construction_if &operator=(const allow_move_construction_if &) = default;

        allow_move_construction_if &operator=(allow_move_construction_if &&) = default;
    };

    template <typename T>
    class allow_move_construction_if<T, false> : public T
    {
    public:
        using T::T;

        constexpr allow_move_construction_if() = default;

        allow_move_construction_if(const allow_move_construction_if &) = default;

        allow_move_construction_if(allow_move_construction_if &&) = delete;

        allow_move_construction_if &operator=(const allow_move_construction_if &) = default;

        allow_move_construction_if &operator=(allow_move_construction_if &&) = default;
    };

    template <typename T, bool>
    class allow_copy_construction_if : public T
    {
    public:
        using T::T;

        constexpr allow_copy_construction_if() = default;

        allow_copy_construction_if(const allow_copy_construction_if &) = default;

        allow_copy_construction_if(allow_copy_construction_if &&) = default;

        allow_copy_construction_if &operator=(const allow_copy_construction_if &) = default;

        allow_copy_construction_if &operator=(allow_copy_construction_if &&) = default;
    };

    template <typename T>
    class allow_copy_construction_if<T, false> : public T
    {
    public:
        using T::T;

        constexpr allow_copy_construction_if() = default;

        allow_copy_construction_if(const allow_copy_construction_if &) = delete;

        allow_copy_construction_if(allow_copy_construction_if &&) = default;

        allow_copy_construction_if &operator=(const allow_copy_construction_if &) = default;

        allow_copy_construction_if &operator=(allow_copy_construction_if &&) = default;
    };

    template <typename T, bool>
    class allow_move_assignment_if : public T
    {
    public:
        using T::T;

        constexpr allow_move_assignment_if() = default;

        allow_move_assignment_if(const allow_move_assignment_if &) = default;

        allow_move_assignment_if(allow_move_assignment_if &&) = default;

        allow_move_assignment_if &operator=(const allow_move_assignment_if &) = default;

        allow_move_assignment_if &operator=(allow_move_assignment_if &&) = default;
    };

    template <typename T>
    class allow_move_assignment_if<T, false> : public T
    {
    public:
        using T::T;

        constexpr allow_move_assignment_if() = default;

        allow_move_assignment_if(const allow_move_assignment_if &) = default;

        allow_move_assignment_if(allow_move_assignment_if &&) = default;

        allow_move_assignment_if &operator=(const allow_move_assignment_if &) = default;

        allow_move_assignment_if &operator=(allow_move_assignment_if &&) = delete;
    };

    template <typename T, bool>
    class allow_copy_assignment_if : public T
    {
    public:
        using T::T;

        constexpr allow_copy_assignment_if() = default;

        allow_copy_assignment_if(const allow_copy_assignment_if &) = default;

        allow_copy_assignment_if(allow_copy_assignment_if &&) = default;

        allow_copy_assignment_if &operator=(const allow_copy_assignment_if &) = default;

        allow_copy_assignment_if &operator=(allow_copy_assignment_if &&) = default;
    };

    template <typename T>
    class allow_copy_assignment_if<T, false> : public T
    {
    public:
        using T::T;

        constexpr allow_copy_assignment_if() = default;

        allow_copy_assignment_if(const allow_copy_assignment_if &) = default;

        allow_copy_assignment_if(allow_copy_assignment_if &&) = default;

        allow_copy_assignment_if &operator=(const allow_copy_assignment_if &) = delete;

        allow_copy_assignment_if &operator=(allow_copy_assignment_if &&) = default;
    };

    template <
        typename T,
        bool AllowCopyConstruction,
        bool AllowMoveConstruction,
        bool AllowCopyAssignment,
        bool AllowMoveAssignment
    >
    class allow_copy_and_move_if : public allow_copy_assignment_if<
        allow_move_assignment_if<
            allow_copy_construction_if<
                allow_move_construction_if<
                    T, AllowMoveConstruction
                >, AllowCopyConstruction
            >, AllowMoveAssignment
        >, AllowCopyAssignment
    >
    {
    public:
        using allow_copy_assignment_if<
            allow_move_assignment_if<
                allow_copy_construction_if<
                    allow_move_construction_if<
                        T, AllowMoveConstruction
                    >, AllowCopyConstruction
                >, AllowMoveAssignment
            >, AllowCopyAssignment>::allow_copy_assignment_if;

        constexpr allow_copy_and_move_if() = default;
    };
}


#endif /* !META_UTILS_ALLOW_COPY_MOVE_OPERATIONS_HPP */
