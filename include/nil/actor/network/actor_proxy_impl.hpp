//---------------------------------------------------------------------------//
// Copyright (c) 2011-2019 Dominik Charousset
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
//
// Distributed under the terms and conditions of the BSD 3-Clause License or
// (at your option) under the terms and conditions of the Boost Software
// License 1.0. See accompanying files LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt.
//---------------------------------------------------------------------------//

#pragma once

#include <nil/actor/actor_proxy.hpp>
#include <nil/actor/network/endpoint_manager.hpp>

namespace nil {
    namespace actor {
        namespace network {

            /// Implements a simple proxy forwarding all operations to a manager.
            class actor_proxy_impl : public actor_proxy {
                public:
                    using super = actor_proxy;

                    actor_proxy_impl(actor_config &cfg, endpoint_manager_ptr dst);

                    ~actor_proxy_impl() override;

                    void enqueue(mailbox_element_ptr what, execution_unit *context) override;

                    void kill_proxy(execution_unit *ctx, error rsn) override;

                private:
                    endpoint_manager_ptr dst_;
            };
        }    // namespace nil::actor::network
    }    // namespace actor
}    // namespace nil
