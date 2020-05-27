import os
import earthpy.plot as ep
import tarfile

def get_earth_explorer_username():
    return os.environ['earth_explorer_username']

def get_earth_explorer_password():
    return os.environ['earth_explorer_password']

def plot_map(ds, indexes=[0,1,2], stretch=True):
    ep.plot_rgb(ds.ReadAsArray(), rgb=indexes, stretch=stretch)

def plot_bands(ds):
    ep.plot_bands(ds)

def untar(in_path, out_path):
    if not os.path.exists(out_path):
        os.makedirs(out_path)
    with tarfile.open(in_path) as tar:
        tar.extractall(out_path)