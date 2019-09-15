/*
** Created by doom on 30/12/18.
*/

#ifndef META_SEQUENCE_DETAILS_FOLDL_HELPER_HPP
#define META_SEQUENCE_DETAILS_FOLDL_HELPER_HPP

#include <cstddef>

namespace doom::meta
{
    template <typename ...Types>
    struct list;

    namespace details
    {
        inline constexpr size_t choose_foldl_step(size_t n) noexcept
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
            if (n >= 2)
                return 2;
            if (n >= 1)
                return 1;
            return 0;
        }

        template <std::size_t Step>
        struct foldl_helper;

        template <>
        struct foldl_helper<64>
        {
            template <template <typename...> typename MetaF, typename Initial,
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
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<MetaF<MetaF<
                    MetaF<MetaF<MetaF<MetaF<
                        MetaF<MetaF<MetaF<MetaF<
                            MetaF<MetaF<MetaF<MetaF<
                                MetaF<MetaF<MetaF<MetaF<
                                    MetaF<MetaF<MetaF<MetaF<
                                        MetaF<MetaF<MetaF<MetaF<
                                            MetaF<MetaF<MetaF<MetaF<
                                                MetaF<MetaF<MetaF<MetaF<
                                                    MetaF<MetaF<MetaF<MetaF<
                                                        MetaF<MetaF<MetaF<MetaF<
                                                            MetaF<MetaF<MetaF<MetaF<
                                                                MetaF<MetaF<MetaF<MetaF<
                                                                    MetaF<MetaF<MetaF<MetaF<
                                                                        MetaF<MetaF<MetaF<MetaF<
                                                                            MetaF<MetaF<MetaF<MetaF<Initial,
                                                                                T000>, T001>, T002>, T003>,
                                                                            T004>, T005>, T006>, T007>,
                                                                        T008>, T009>, T010>, T011>,
                                                                    T012>, T013>, T014>, T015>,
                                                                T016>, T017>, T018>, T019>,
                                                            T020>, T021>, T022>, T023>,
                                                        T024>, T025>, T026>, T027>,
                                                    T028>, T029>, T030>, T031>,
                                                T032>, T033>, T034>, T035>,
                                            T036>, T037>, T038>, T039>,
                                        T040>, T041>, T042>, T043>,
                                    T044>, T045>, T046>, T047>,
                                T048>, T049>, T050>, T051>,
                            T052>, T053>, T054>, T055>,
                        T056>, T057>, T058>, T059>,
                    T060>, T061>, T062>, T063>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<32>
        {
            template <template <typename...> typename MetaF, typename Initial,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename T016, typename T017, typename T018, typename T019,
                typename T020, typename T021, typename T022, typename T023,
                typename T024, typename T025, typename T026, typename T027,
                typename T028, typename T029, typename T030, typename T031,
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<
                    MetaF<MetaF<
                        MetaF<MetaF<
                            MetaF<MetaF<
                                MetaF<MetaF<
                                    MetaF<MetaF<
                                        MetaF<MetaF<
                                            MetaF<MetaF<
                                                MetaF<MetaF<
                                                    MetaF<MetaF<
                                                        MetaF<MetaF<
                                                            MetaF<MetaF<
                                                                MetaF<MetaF<
                                                                    MetaF<MetaF<
                                                                        MetaF<MetaF<
                                                                            MetaF<MetaF<Initial, T000>, T001>,
                                                                            T002>, T003>,
                                                                        T004>, T005>,
                                                                    T006>, T007>,
                                                                T008>, T009>,
                                                            T010>, T011>,
                                                        T012>, T013>,
                                                    T014>, T015>,
                                                T016>, T017>,
                                            T018>, T019>,
                                        T020>, T021>,
                                    T022>, T023>,
                                T024>, T025>,
                            T026>, T027>,
                        T028>, T029>,
                    T030>, T031>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<16>
        {
            template <template <typename...> typename MetaF, typename Initial,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename T008, typename T009, typename T010, typename T011,
                typename T012, typename T013, typename T014, typename T015,
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<
                    MetaF<MetaF<
                        MetaF<MetaF<
                            MetaF<MetaF<
                                MetaF<MetaF<
                                    MetaF<MetaF<
                                        MetaF<MetaF<
                                            MetaF<MetaF<Initial, T000>, T001>,
                                            T002>, T003>,
                                        T004>, T005>,
                                    T006>, T007>,
                                T008>, T009>,
                            T010>, T011>,
                        T012>, T013>,
                    T014>, T015>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<8>
        {
            template <template <typename...> typename MetaF, typename Initial,
                typename T000, typename T001, typename T002, typename T003,
                typename T004, typename T005, typename T006, typename T007,
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<
                    MetaF<MetaF<
                        MetaF<MetaF<
                            MetaF<MetaF<Initial, T000>, T001>,
                            T002>, T003>,
                        T004>, T005>,
                    T006>, T007>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<4>
        {
            template <template <typename...> typename MetaF, typename Initial,
                typename T000, typename T001, typename T002, typename T003,
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<MetaF<MetaF<Initial, T000>, T001>, T002>, T003>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<2>
        {
            template <template <typename...> typename MetaF, typename Initial,
                typename T000, typename T001,
                typename ...Ts
            >
            using f = typename foldl_helper<choose_foldl_step(sizeof...(Ts))>::template f<
                MetaF,
                MetaF<MetaF<Initial, T000>, T001>,
                Ts...
            >;
        };

        template <>
        struct foldl_helper<1>
        {
            template <template <typename...> typename MetaF, typename Initial, typename T000>
            using f = MetaF<Initial, T000>;
        };

        template <>
        struct foldl_helper<0>
        {
            template <template <typename...> typename MetaF, typename Initial>
            using f = Initial;
        };
    }
}

#endif /* !META_SEQUENCE_DETAILS_FOLDL_HELPER_HPP */
