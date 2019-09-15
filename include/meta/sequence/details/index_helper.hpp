/*
** Created by doom on 12/01/19.
*/

#ifndef META_SEQUENCE_DETAILS_INDEX_HELPER_HPP
#define META_SEQUENCE_DETAILS_INDEX_HELPER_HPP

#include <cstddef>

namespace doom::meta
{
    template <typename ...Types>
    struct list;

    namespace details
    {
        template <std::size_t N>
        struct index_helper;

        inline constexpr std::size_t choose_index_step(std::size_t n) noexcept
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

        template <>
        struct index_helper<64>
        {
            template <template <typename> typename MetaF, std::size_t N,
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
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                MetaF<T003>::value ? N + 3 :
                MetaF<T004>::value ? N + 4 :
                MetaF<T005>::value ? N + 5 :
                MetaF<T006>::value ? N + 6 :
                MetaF<T007>::value ? N + 7 :
                MetaF<T008>::value ? N + 8 :
                MetaF<T009>::value ? N + 9 :
                MetaF<T010>::value ? N + 10 :
                MetaF<T011>::value ? N + 11 :
                MetaF<T012>::value ? N + 12 :
                MetaF<T013>::value ? N + 13 :
                MetaF<T014>::value ? N + 14 :
                MetaF<T015>::value ? N + 15 :
                MetaF<T016>::value ? N + 16 :
                MetaF<T017>::value ? N + 17 :
                MetaF<T018>::value ? N + 18 :
                MetaF<T019>::value ? N + 19 :
                MetaF<T020>::value ? N + 20 :
                MetaF<T021>::value ? N + 21 :
                MetaF<T022>::value ? N + 22 :
                MetaF<T023>::value ? N + 23 :
                MetaF<T024>::value ? N + 24 :
                MetaF<T025>::value ? N + 25 :
                MetaF<T026>::value ? N + 26 :
                MetaF<T027>::value ? N + 27 :
                MetaF<T028>::value ? N + 28 :
                MetaF<T029>::value ? N + 29 :
                MetaF<T030>::value ? N + 30 :
                MetaF<T031>::value ? N + 31 :
                MetaF<T032>::value ? N + 32 :
                MetaF<T033>::value ? N + 33 :
                MetaF<T034>::value ? N + 34 :
                MetaF<T035>::value ? N + 35 :
                MetaF<T036>::value ? N + 36 :
                MetaF<T037>::value ? N + 37 :
                MetaF<T038>::value ? N + 38 :
                MetaF<T039>::value ? N + 39 :
                MetaF<T040>::value ? N + 40 :
                MetaF<T041>::value ? N + 41 :
                MetaF<T042>::value ? N + 42 :
                MetaF<T043>::value ? N + 43 :
                MetaF<T044>::value ? N + 44 :
                MetaF<T045>::value ? N + 45 :
                MetaF<T046>::value ? N + 46 :
                MetaF<T047>::value ? N + 47 :
                MetaF<T048>::value ? N + 48 :
                MetaF<T049>::value ? N + 49 :
                MetaF<T050>::value ? N + 50 :
                MetaF<T051>::value ? N + 51 :
                MetaF<T052>::value ? N + 52 :
                MetaF<T053>::value ? N + 53 :
                MetaF<T054>::value ? N + 54 :
                MetaF<T055>::value ? N + 55 :
                MetaF<T056>::value ? N + 56 :
                MetaF<T057>::value ? N + 57 :
                MetaF<T058>::value ? N + 58 :
                MetaF<T059>::value ? N + 59 :
                MetaF<T060>::value ? N + 60 :
                MetaF<T061>::value ? N + 61 :
                MetaF<T062>::value ? N + 62 :
                MetaF<T063>::value ? N + 63 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 64, Ts...>;
        };

        template <>
        struct index_helper<32>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename T016, typename T017, typename T018, typename T019,
                typename T020, typename T021, typename T022, typename T023,
                typename T024, typename T025, typename T026, typename T027,
                typename T028, typename T029, typename T030, typename T031,
                typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                MetaF<T003>::value ? N + 3 :
                MetaF<T004>::value ? N + 4 :
                MetaF<T005>::value ? N + 5 :
                MetaF<T006>::value ? N + 6 :
                MetaF<T007>::value ? N + 7 :
                MetaF<T008>::value ? N + 8 :
                MetaF<T009>::value ? N + 9 :
                MetaF<T010>::value ? N + 10 :
                MetaF<T011>::value ? N + 11 :
                MetaF<T012>::value ? N + 12 :
                MetaF<T013>::value ? N + 13 :
                MetaF<T014>::value ? N + 14 :
                MetaF<T015>::value ? N + 15 :
                MetaF<T016>::value ? N + 16 :
                MetaF<T017>::value ? N + 17 :
                MetaF<T018>::value ? N + 18 :
                MetaF<T019>::value ? N + 19 :
                MetaF<T020>::value ? N + 20 :
                MetaF<T021>::value ? N + 21 :
                MetaF<T022>::value ? N + 22 :
                MetaF<T023>::value ? N + 23 :
                MetaF<T024>::value ? N + 24 :
                MetaF<T025>::value ? N + 25 :
                MetaF<T026>::value ? N + 26 :
                MetaF<T027>::value ? N + 27 :
                MetaF<T028>::value ? N + 28 :
                MetaF<T029>::value ? N + 29 :
                MetaF<T030>::value ? N + 30 :
                MetaF<T031>::value ? N + 31 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 32, Ts...>;
        };

        template <>
        struct index_helper<16>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                MetaF<T003>::value ? N + 3 :
                MetaF<T004>::value ? N + 4 :
                MetaF<T005>::value ? N + 5 :
                MetaF<T006>::value ? N + 6 :
                MetaF<T007>::value ? N + 7 :
                MetaF<T008>::value ? N + 8 :
                MetaF<T009>::value ? N + 9 :
                MetaF<T010>::value ? N + 10 :
                MetaF<T011>::value ? N + 11 :
                MetaF<T012>::value ? N + 12 :
                MetaF<T013>::value ? N + 13 :
                MetaF<T014>::value ? N + 14 :
                MetaF<T015>::value ? N + 15 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 16, Ts...>;
        };

        template <>
        struct index_helper<8>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                MetaF<T003>::value ? N + 3 :
                MetaF<T004>::value ? N + 4 :
                MetaF<T005>::value ? N + 5 :
                MetaF<T006>::value ? N + 6 :
                MetaF<T007>::value ? N + 7 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 8, Ts...>;
        };

        template <>
        struct index_helper<4>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename T002, typename T003, typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                MetaF<T003>::value ? N + 3 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 4, Ts...>;
        };

        template <>
        struct index_helper<3>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename T002, typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                MetaF<T002>::value ? N + 2 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 3, Ts...>;
        };

        template <>
        struct index_helper<2>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename T001, typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                MetaF<T001>::value ? N + 1 :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 2, Ts...>;
        };

        template <>
        struct index_helper<1>
        {
            template <template <typename> typename MetaF, std::size_t N,
                typename T000, typename ...Ts>
            static constexpr std::size_t f =
                MetaF<T000>::value ? N :
                index_helper<choose_index_step(sizeof...(Ts))>::template f<MetaF, N + 1, Ts...>;
        };

        template <>
        struct index_helper<0>
        {
            template <template <typename> typename, std::size_t N, typename ...Ts>
            static constexpr std::size_t f = N;
        };
    }
}

#endif /* !META_SEQUENCE_DETAILS_INDEX_HELPER_HPP */
