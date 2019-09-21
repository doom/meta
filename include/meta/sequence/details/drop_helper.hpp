/*
** Created by doom on 02/01/19.
*/

#ifndef META_SEQUENCE_DETAILS_DROP_HELPER_HPP
#define META_SEQUENCE_DETAILS_DROP_HELPER_HPP

#include <cstddef>

namespace doom::meta
{
    template <typename ...Types>
    struct list;

    namespace details
    {
        inline constexpr std::size_t simplify_drop_num(std::size_t n, std::size_t list_size) noexcept
        {
            return list_size < n ? list_size : n;
        }

        inline constexpr std::size_t choose_drop_step(std::size_t n) noexcept
        {
            if (n >= 64)
                return 64;
            if (n >= 32)
                return 32;
            if (n >= 16)
                return 16;
            if (n >= 8)
                return 8;
            if (n >= 4)
                return 4;
            return n;
        }

        template <std::size_t NbToRotate>
        struct drop_helper;

        template <>
        struct drop_helper<64>
        {
            template <std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename T016, typename T017, typename T018, typename T019,
                typename T020, typename T021, typename T022, typename T023,
                typename T024, typename T025, typename T026, typename T027,
                typename T028, typename T029, typename T030, typename T031,
                typename T032, typename T033, typename T034, typename T035,
                typename T036, typename T037, typename T038, typename T039,
                typename T040, typename T041, typename T042, typename T043,
                typename T044, typename T045, typename T046, typename T047,
                typename T048, typename T049, typename T050, typename T051,
                typename T052, typename T053, typename T054, typename T055,
                typename T056, typename T057, typename T058, typename T059,
                typename T060, typename T061, typename T062, typename T063,
                typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 64)>::template f<N - 64, Ts...>;
        };

        template <>
        struct drop_helper<32>
        {
            template <std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename T016, typename T017, typename T018, typename T019,
                typename T020, typename T021, typename T022, typename T023,
                typename T024, typename T025, typename T026, typename T027,
                typename T028, typename T029, typename T030, typename T031,
                typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 32)>::template f<N - 32, Ts...>;
        };

        template <>
        struct drop_helper<16>
        {
            template <std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 16)>::template f<N - 16, Ts...>;
        };

        template <>
        struct drop_helper<8>
        {
            template <std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 8)>::template f<N - 8, Ts...>;
        };

        template <>
        struct drop_helper<4>
        {
            template <std::size_t N, typename T001, typename T002, typename T003, typename T004, typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 4)>::template f<N - 4, Ts...>;
        };

        template <>
        struct drop_helper<3>
        {
            template <std::size_t N, typename T000, typename T001, typename T002, typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 3)>::template f<N - 3, Ts...>;
        };

        template <>
        struct drop_helper<2>
        {
            template <std::size_t N, typename T000, typename T001, typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 2)>::template f<N - 2, Ts...>;
        };

        template <>
        struct drop_helper<1>
        {
            template <std::size_t N, typename T000, typename ...Ts>
            using f = typename drop_helper<choose_drop_step(N - 1)>::template f<N - 1, Ts...>;
        };

        template <>
        struct drop_helper<0>
        {
            template <std::size_t N, typename ...Ts>
            using f = list<Ts...>;
        };
    }
}

#endif /* !META_SEQUENCE_DETAILS_DROP_HELPER_HPP */
