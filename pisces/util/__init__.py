# -*_ coding: utf-8 -*-

import os
import os.path

__all__ = [pck.split('.')[0] for pck in os.listdir(os.path.split(os.path.realpath(__file__))[0]) if pck.endswith('.py') and pck != __file__ or os.path.isdir(os.path.join(os.path.realpath(__file__), pck))]
