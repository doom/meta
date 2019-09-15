/*
** Created by doom on 31/10/18.
*/

#ifndef META_SEQUENCE_DETAILS_FLATTEN_HELPER_HPP
#define META_SEQUENCE_DETAILS_FLATTEN_HELPER_HPP

#include <cstddef>

namespace doom::meta
{
    template <typename ...Types>
    struct list;

    namespace details
    {
        template <std::size_t UpperPow2>
        struct flatten_helper;

        template <>
        struct flatten_helper<7>
        {
            template <
                typename L000, typename L001, typename L002, typename L003,
                typename L004, typename L005, typename L006, typename L007,
                typename L008, typename L009, typename L010, typename L011,
                typename L012, typename L013, typename L014, typename L015,
                typename L016, typename L017, typename L018, typename L019,
                typename L020, typename L021, typename L022, typename L023,
                typename L024, typename L025, typename L026, typename L027,
                typename L028, typename L029, typename L030, typename L031,
                typename L032, typename L033, typename L034, typename L035,
                typename L036, typename L037, typename L038, typename L039,
                typename L040, typename L041, typename L042, typename L043,
                typename L044, typename L045, typename L046, typename L047,
                typename L048, typename L049, typename L050, typename L051,
                typename L052, typename L053, typename L054, typename L055,
                typename L056, typename L057, typename L058, typename L059,
                typename L060, typename L061, typename L062, typename L063,
                typename L064, typename L065 = list<>, typename L066 = list<>, typename L067 = list<>,
                typename L068 = list<>, typename L069 = list<>, typename L070 = list<>, typename L071 = list<>,
                typename L072 = list<>, typename L073 = list<>, typename L074 = list<>, typename L075 = list<>,
                typename L076 = list<>, typename L077 = list<>, typename L078 = list<>, typename L079 = list<>,
                typename L080 = list<>, typename L081 = list<>, typename L082 = list<>, typename L083 = list<>,
                typename L084 = list<>, typename L085 = list<>, typename L086 = list<>, typename L087 = list<>,
                typename L088 = list<>, typename L089 = list<>, typename L090 = list<>, typename L091 = list<>,
                typename L092 = list<>, typename L093 = list<>, typename L094 = list<>, typename L095 = list<>,
                typename L096 = list<>, typename L097 = list<>, typename L098 = list<>, typename L099 = list<>,
                typename L100 = list<>, typename L101 = list<>, typename L102 = list<>, typename L103 = list<>,
                typename L104 = list<>, typename L105 = list<>, typename L106 = list<>, typename L107 = list<>,
                typename L108 = list<>, typename L109 = list<>, typename L110 = list<>, typename L111 = list<>,
                typename L112 = list<>, typename L113 = list<>, typename L114 = list<>, typename L115 = list<>,
                typename L116 = list<>, typename L117 = list<>, typename L118 = list<>, typename L119 = list<>,
                typename L120 = list<>, typename L121 = list<>, typename L122 = list<>, typename L123 = list<>,
                typename L124 = list<>, typename L125 = list<>, typename L126 = list<>, typename L127 = list<>
            >
            struct f;

            template <
                typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003,
                typename ...Ts004, typename ...Ts005, typename ...Ts006, typename ...Ts007,
                typename ...Ts008, typename ...Ts009, typename ...Ts010, typename ...Ts011,
                typename ...Ts012, typename ...Ts013, typename ...Ts014, typename ...Ts015,
                typename ...Ts016, typename ...Ts017, typename ...Ts018, typename ...Ts019,
                typename ...Ts020, typename ...Ts021, typename ...Ts022, typename ...Ts023,
                typename ...Ts024, typename ...Ts025, typename ...Ts026, typename ...Ts027,
                typename ...Ts028, typename ...Ts029, typename ...Ts030, typename ...Ts031,
                typename ...Ts032, typename ...Ts033, typename ...Ts034, typename ...Ts035,
                typename ...Ts036, typename ...Ts037, typename ...Ts038, typename ...Ts039,
                typename ...Ts040, typename ...Ts041, typename ...Ts042, typename ...Ts043,
                typename ...Ts044, typename ...Ts045, typename ...Ts046, typename ...Ts047,
                typename ...Ts048, typename ...Ts049, typename ...Ts050, typename ...Ts051,
                typename ...Ts052, typename ...Ts053, typename ...Ts054, typename ...Ts055,
                typename ...Ts056, typename ...Ts057, typename ...Ts058, typename ...Ts059,
                typename ...Ts060, typename ...Ts061, typename ...Ts062, typename ...Ts063,
                typename ...Ts064, typename ...Ts065, typename ...Ts066, typename ...Ts067,
                typename ...Ts068, typename ...Ts069, typename ...Ts070, typename ...Ts071,
                typename ...Ts072, typename ...Ts073, typename ...Ts074, typename ...Ts075,
                typename ...Ts076, typename ...Ts077, typename ...Ts078, typename ...Ts079,
                typename ...Ts080, typename ...Ts081, typename ...Ts082, typename ...Ts083,
                typename ...Ts084, typename ...Ts085, typename ...Ts086, typename ...Ts087,
                typename ...Ts088, typename ...Ts089, typename ...Ts090, typename ...Ts091,
                typename ...Ts092, typename ...Ts093, typename ...Ts094, typename ...Ts095,
                typename ...Ts096, typename ...Ts097, typename ...Ts098, typename ...Ts099,
                typename ...Ts100, typename ...Ts101, typename ...Ts102, typename ...Ts103,
                typename ...Ts104, typename ...Ts105, typename ...Ts106, typename ...Ts107,
                typename ...Ts108, typename ...Ts109, typename ...Ts110, typename ...Ts111,
                typename ...Ts112, typename ...Ts113, typename ...Ts114, typename ...Ts115,
                typename ...Ts116, typename ...Ts117, typename ...Ts118, typename ...Ts119,
                typename ...Ts120, typename ...Ts121, typename ...Ts122, typename ...Ts123,
                typename ...Ts124, typename ...Ts125, typename ...Ts126, typename ...Ts127
            >
            struct f<
                list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>,
                list<Ts004...>, list<Ts005...>, list<Ts006...>, list<Ts007...>,
                list<Ts008...>, list<Ts009...>, list<Ts010...>, list<Ts011...>,
                list<Ts012...>, list<Ts013...>, list<Ts014...>, list<Ts015...>,
                list<Ts016...>, list<Ts017...>, list<Ts018...>, list<Ts019...>,
                list<Ts020...>, list<Ts021...>, list<Ts022...>, list<Ts023...>,
                list<Ts024...>, list<Ts025...>, list<Ts026...>, list<Ts027...>,
                list<Ts028...>, list<Ts029...>, list<Ts030...>, list<Ts031...>,
                list<Ts032...>, list<Ts033...>, list<Ts034...>, list<Ts035...>,
                list<Ts036...>, list<Ts037...>, list<Ts038...>, list<Ts039...>,
                list<Ts040...>, list<Ts041...>, list<Ts042...>, list<Ts043...>,
                list<Ts044...>, list<Ts045...>, list<Ts046...>, list<Ts047...>,
                list<Ts048...>, list<Ts049...>, list<Ts050...>, list<Ts051...>,
                list<Ts052...>, list<Ts053...>, list<Ts054...>, list<Ts055...>,
                list<Ts056...>, list<Ts057...>, list<Ts058...>, list<Ts059...>,
                list<Ts060...>, list<Ts061...>, list<Ts062...>, list<Ts063...>,
                list<Ts064...>, list<Ts065...>, list<Ts066...>, list<Ts067...>,
                list<Ts068...>, list<Ts069...>, list<Ts070...>, list<Ts071...>,
                list<Ts072...>, list<Ts073...>, list<Ts074...>, list<Ts075...>,
                list<Ts076...>, list<Ts077...>, list<Ts078...>, list<Ts079...>,
                list<Ts080...>, list<Ts081...>, list<Ts082...>, list<Ts083...>,
                list<Ts084...>, list<Ts085...>, list<Ts086...>, list<Ts087...>,
                list<Ts088...>, list<Ts089...>, list<Ts090...>, list<Ts091...>,
                list<Ts092...>, list<Ts093...>, list<Ts094...>, list<Ts095...>,
                list<Ts096...>, list<Ts097...>, list<Ts098...>, list<Ts099...>,
                list<Ts100...>, list<Ts101...>, list<Ts102...>, list<Ts103...>,
                list<Ts104...>, list<Ts105...>, list<Ts106...>, list<Ts107...>,
                list<Ts108...>, list<Ts109...>, list<Ts110...>, list<Ts111...>,
                list<Ts112...>, list<Ts113...>, list<Ts114...>, list<Ts115...>,
                list<Ts116...>, list<Ts117...>, list<Ts118...>, list<Ts119...>,
                list<Ts120...>, list<Ts121...>, list<Ts122...>, list<Ts123...>,
                list<Ts124...>, list<Ts125...>, list<Ts126...>, list<Ts127...>
            >
            {
                using type = list<
                    Ts000..., Ts001..., Ts002..., Ts003..., Ts004..., Ts005..., Ts006..., Ts007...,
                    Ts008..., Ts009..., Ts010..., Ts011..., Ts012..., Ts013..., Ts014..., Ts015...,
                    Ts016..., Ts017..., Ts018..., Ts019..., Ts020..., Ts021..., Ts022..., Ts023...,
                    Ts024..., Ts025..., Ts026..., Ts027..., Ts028..., Ts029..., Ts030..., Ts031...,
                    Ts032..., Ts033..., Ts034..., Ts035..., Ts036..., Ts037..., Ts038..., Ts039...,
                    Ts040..., Ts041..., Ts042..., Ts043..., Ts044..., Ts045..., Ts046..., Ts047...,
                    Ts048..., Ts049..., Ts050..., Ts051..., Ts052..., Ts053..., Ts054..., Ts055...,
                    Ts056..., Ts057..., Ts058..., Ts059..., Ts060..., Ts061..., Ts062..., Ts063...,
                    Ts064..., Ts065..., Ts066..., Ts067..., Ts068..., Ts069..., Ts070..., Ts071...,
                    Ts072..., Ts073..., Ts074..., Ts075..., Ts076..., Ts077..., Ts078..., Ts079...,
                    Ts080..., Ts081..., Ts082..., Ts083..., Ts084..., Ts085..., Ts086..., Ts087...,
                    Ts088..., Ts089..., Ts090..., Ts091..., Ts092..., Ts093..., Ts094..., Ts095...,
                    Ts096..., Ts097..., Ts098..., Ts099..., Ts100..., Ts101..., Ts102..., Ts103...,
                    Ts104..., Ts105..., Ts106..., Ts107..., Ts108..., Ts109..., Ts110..., Ts111...,
                    Ts112..., Ts113..., Ts114..., Ts115..., Ts116..., Ts117..., Ts118..., Ts119...,
                    Ts120..., Ts121..., Ts122..., Ts123..., Ts124..., Ts125..., Ts126..., Ts127...
                >;
            };
        };

        template <>
        struct flatten_helper<6>
        {
            template <
                typename L000, typename L001, typename L002, typename L003,
                typename L004, typename L005, typename L006, typename L007,
                typename L008, typename L009, typename L010, typename L011,
                typename L012, typename L013, typename L014, typename L015,
                typename L016, typename L017, typename L018, typename L019,
                typename L020, typename L021, typename L022, typename L023,
                typename L024, typename L025, typename L026, typename L027,
                typename L028, typename L029, typename L030, typename L031,
                typename L032, typename L033 = list<>, typename L034 = list<>, typename L035 = list<>,
                typename L036 = list<>, typename L037 = list<>, typename L038 = list<>, typename L039 = list<>,
                typename L040 = list<>, typename L041 = list<>, typename L042 = list<>, typename L043 = list<>,
                typename L044 = list<>, typename L045 = list<>, typename L046 = list<>, typename L047 = list<>,
                typename L048 = list<>, typename L049 = list<>, typename L050 = list<>, typename L051 = list<>,
                typename L052 = list<>, typename L053 = list<>, typename L054 = list<>, typename L055 = list<>,
                typename L056 = list<>, typename L057 = list<>, typename L058 = list<>, typename L059 = list<>,
                typename L060 = list<>, typename L061 = list<>, typename L062 = list<>, typename L063 = list<>
            >
            struct f;

            template <
                typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003,
                typename ...Ts004, typename ...Ts005, typename ...Ts006, typename ...Ts007,
                typename ...Ts008, typename ...Ts009, typename ...Ts010, typename ...Ts011,
                typename ...Ts012, typename ...Ts013, typename ...Ts014, typename ...Ts015,
                typename ...Ts016, typename ...Ts017, typename ...Ts018, typename ...Ts019,
                typename ...Ts020, typename ...Ts021, typename ...Ts022, typename ...Ts023,
                typename ...Ts024, typename ...Ts025, typename ...Ts026, typename ...Ts027,
                typename ...Ts028, typename ...Ts029, typename ...Ts030, typename ...Ts031,
                typename ...Ts032, typename ...Ts033, typename ...Ts034, typename ...Ts035,
                typename ...Ts036, typename ...Ts037, typename ...Ts038, typename ...Ts039,
                typename ...Ts040, typename ...Ts041, typename ...Ts042, typename ...Ts043,
                typename ...Ts044, typename ...Ts045, typename ...Ts046, typename ...Ts047,
                typename ...Ts048, typename ...Ts049, typename ...Ts050, typename ...Ts051,
                typename ...Ts052, typename ...Ts053, typename ...Ts054, typename ...Ts055,
                typename ...Ts056, typename ...Ts057, typename ...Ts058, typename ...Ts059,
                typename ...Ts060, typename ...Ts061, typename ...Ts062, typename ...Ts063
            >
            struct f<
                list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>,
                list<Ts004...>, list<Ts005...>, list<Ts006...>, list<Ts007...>,
                list<Ts008...>, list<Ts009...>, list<Ts010...>, list<Ts011...>,
                list<Ts012...>, list<Ts013...>, list<Ts014...>, list<Ts015...>,
                list<Ts016...>, list<Ts017...>, list<Ts018...>, list<Ts019...>,
                list<Ts020...>, list<Ts021...>, list<Ts022...>, list<Ts023...>,
                list<Ts024...>, list<Ts025...>, list<Ts026...>, list<Ts027...>,
                list<Ts028...>, list<Ts029...>, list<Ts030...>, list<Ts031...>,
                list<Ts032...>, list<Ts033...>, list<Ts034...>, list<Ts035...>,
                list<Ts036...>, list<Ts037...>, list<Ts038...>, list<Ts039...>,
                list<Ts040...>, list<Ts041...>, list<Ts042...>, list<Ts043...>,
                list<Ts044...>, list<Ts045...>, list<Ts046...>, list<Ts047...>,
                list<Ts048...>, list<Ts049...>, list<Ts050...>, list<Ts051...>,
                list<Ts052...>, list<Ts053...>, list<Ts054...>, list<Ts055...>,
                list<Ts056...>, list<Ts057...>, list<Ts058...>, list<Ts059...>,
                list<Ts060...>, list<Ts061...>, list<Ts062...>, list<Ts063...>
            >
            {
                using type = list<
                    Ts000..., Ts001..., Ts002..., Ts003..., Ts004..., Ts005..., Ts006..., Ts007...,
                    Ts008..., Ts009..., Ts010..., Ts011..., Ts012..., Ts013..., Ts014..., Ts015...,
                    Ts016..., Ts017..., Ts018..., Ts019..., Ts020..., Ts021..., Ts022..., Ts023...,
                    Ts024..., Ts025..., Ts026..., Ts027..., Ts028..., Ts029..., Ts030..., Ts031...,
                    Ts032..., Ts033..., Ts034..., Ts035..., Ts036..., Ts037..., Ts038..., Ts039...,
                    Ts040..., Ts041..., Ts042..., Ts043..., Ts044..., Ts045..., Ts046..., Ts047...,
                    Ts048..., Ts049..., Ts050..., Ts051..., Ts052..., Ts053..., Ts054..., Ts055...,
                    Ts056..., Ts057..., Ts058..., Ts059..., Ts060..., Ts061..., Ts062..., Ts063...
                >;
            };
        };

        template <>
        struct flatten_helper<5>
        {
            template <
                typename L000, typename L001, typename L002, typename L003,
                typename L004, typename L005, typename L006, typename L007,
                typename L008, typename L009, typename L010, typename L011,
                typename L012, typename L013, typename L014, typename L015,
                typename L016, typename L017 = list<>, typename L018 = list<>, typename L019 = list<>,
                typename L020 = list<>, typename L021 = list<>, typename L022 = list<>, typename L023 = list<>,
                typename L024 = list<>, typename L025 = list<>, typename L026 = list<>, typename L027 = list<>,
                typename L028 = list<>, typename L029 = list<>, typename L030 = list<>, typename L031 = list<>
            >
            struct f;

            template <
                typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003,
                typename ...Ts004, typename ...Ts005, typename ...Ts006, typename ...Ts007,
                typename ...Ts008, typename ...Ts009, typename ...Ts010, typename ...Ts011,
                typename ...Ts012, typename ...Ts013, typename ...Ts014, typename ...Ts015,
                typename ...Ts016, typename ...Ts017, typename ...Ts018, typename ...Ts019,
                typename ...Ts020, typename ...Ts021, typename ...Ts022, typename ...Ts023,
                typename ...Ts024, typename ...Ts025, typename ...Ts026, typename ...Ts027,
                typename ...Ts028, typename ...Ts029, typename ...Ts030, typename ...Ts031
            >
            struct f<
                list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>,
                list<Ts004...>, list<Ts005...>, list<Ts006...>, list<Ts007...>,
                list<Ts008...>, list<Ts009...>, list<Ts010...>, list<Ts011...>,
                list<Ts012...>, list<Ts013...>, list<Ts014...>, list<Ts015...>,
                list<Ts016...>, list<Ts017...>, list<Ts018...>, list<Ts019...>,
                list<Ts020...>, list<Ts021...>, list<Ts022...>, list<Ts023...>,
                list<Ts024...>, list<Ts025...>, list<Ts026...>, list<Ts027...>,
                list<Ts028...>, list<Ts029...>, list<Ts030...>, list<Ts031...>
            >
            {
                using type = list<
                    Ts000..., Ts001..., Ts002..., Ts003..., Ts004..., Ts005..., Ts006..., Ts007...,
                    Ts008..., Ts009..., Ts010..., Ts011..., Ts012..., Ts013..., Ts014..., Ts015...,
                    Ts016..., Ts017..., Ts018..., Ts019..., Ts020..., Ts021..., Ts022..., Ts023...,
                    Ts024..., Ts025..., Ts026..., Ts027..., Ts028..., Ts029..., Ts030..., Ts031...
                >;
            };
        };

        template <>
        struct flatten_helper<4>
        {
            template <
                typename L000, typename L001, typename L002, typename L003,
                typename L004, typename L005, typename L006, typename L007,
                typename L008, typename L009 = list<>, typename L010 = list<>, typename L011 = list<>,
                typename L012 = list<>, typename L013 = list<>, typename L014 = list<>, typename L015 = list<>
            >
            struct f;

            template <
                typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003,
                typename ...Ts004, typename ...Ts005, typename ...Ts006, typename ...Ts007,
                typename ...Ts008, typename ...Ts009, typename ...Ts010, typename ...Ts011,
                typename ...Ts012, typename ...Ts013, typename ...Ts014, typename ...Ts015
            >
            struct f<
                list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>,
                list<Ts004...>, list<Ts005...>, list<Ts006...>, list<Ts007...>,
                list<Ts008...>, list<Ts009...>, list<Ts010...>, list<Ts011...>,
                list<Ts012...>, list<Ts013...>, list<Ts014...>, list<Ts015...>
            >
            {
                using type = list<
                    Ts000..., Ts001..., Ts002..., Ts003..., Ts004..., Ts005..., Ts006..., Ts007...,
                    Ts008..., Ts009..., Ts010..., Ts011..., Ts012..., Ts013..., Ts014..., Ts015...
                >;
            };
        };

        template <>
        struct flatten_helper<3>
        {
            template <
                typename L000, typename L001, typename L002, typename L003,
                typename L004, typename L005 = list<>, typename L006 = list<>, typename L007 = list<>
            >
            struct f;

            template <
                typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003,
                typename ...Ts004, typename ...Ts005, typename ...Ts006, typename ...Ts007
            >
            struct f<
                list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>,
                list<Ts004...>, list<Ts005...>, list<Ts006...>, list<Ts007...>
            >
            {
                using type = list<
                    Ts000..., Ts001..., Ts002..., Ts003..., Ts004..., Ts005..., Ts006..., Ts007...
                >;
            };
        };

        template <>
        struct flatten_helper<2>
        {
            template <typename L000, typename L001, typename L002, typename L003 = list<>>
            struct f;

            template <typename ...Ts000, typename ...Ts001, typename ...Ts002, typename ...Ts003>
            struct f<list<Ts000...>, list<Ts001...>, list<Ts002...>, list<Ts003...>>
            {
                using type = list<Ts000..., Ts001..., Ts002..., Ts003...>;
            };
        };

        template <>
        struct flatten_helper<1>
        {
            template <typename L000, typename L001 = list<>>
            struct f;

            template <typename ...Ts000, typename ...Ts001>
            struct f<list<Ts000...>, list<Ts001...>>
            {
                using type = list<Ts000..., Ts001...>;
            };
        };

        template <>
        struct flatten_helper<0>
        {
            template <typename Ts000>
            struct f
            {
                using type = Ts000;
            };
        };
    }
}

#endif /* !META_SEQUENCE_DETAILS_FLATTEN_HELPER_HPP */
