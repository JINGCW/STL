import torch

# tensor([0.5518, 1.5998, 0.6879])
x = torch.randn(3)
x.mm()
# tensor([[0.5518],[1.5998],[0.6879]])
x.unsqueeze(1)
